#include "Engine.h"
#include "Window.h"

#define DCX_USESTYLE 0x00010000

namespace Win32
{
	Window::Window(std::wstring classTitle, HICON icon, WindowType type)
		: SubObject(classTitle, classTitle, icon), m_Type(type)
	{
		Size(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	}

	Window::~Window()
	{

	}

	VOID Window::Initialize()
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);

		RECT R = { 0, 0, m_Size.cx, m_Size.cy };
		AdjustWindowRect(&R, m_Type, false);
		int width = R.right - R.left;
		int height = R.bottom - R.top;

		m_Handle = CreateWindow(
			m_Class.c_str(),
			m_Title.c_str(),
			m_Type,
			((desktop.right / 2) - (m_Size.cx / 2)),
			((desktop.bottom / 2) - (m_Size.cy / 2)),
			m_Size.cx,
			m_Size.cy,
			0,		// parent window
			0,		// menu window
			HInstance(),
			(void*)this			// give specific instructions to window at runtime to do special things
		);

		ShowWindow(m_Handle, SW_SHOW);
		UpdateWindow(m_Handle);
	}
	LRESULT Window::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		// Client msgs: general high-level messages to change stuff INSIDE the window
		// Non-client msgs: changes the window itself

		switch (msg)
		{
		case WM_NCCREATE: { OnNonClientCreate(); } return TRUE;
		case WM_NCACTIVATE: { OnNonClientActivate(LOWORD(wParam) != WA_INACTIVE); } return TRUE;
		case WM_NCPAINT: { OnNonClientPaint((HRGN)wParam); } return FALSE;
		case WM_TIMER: { RedrawWindow(); } break;
		}

		return SubObject::MessageHandler(hWnd, msg, wParam, lParam);
	}

	VOID Window::RedrawWindow()
	{
		SetWindowPos(Handle(), 0, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_DRAWFRAME | SWP_FRAMECHANGED); // resets window
		SendMessage(Handle(), WM_PAINT, 0, 0);
	}

	VOID Window::OnNonClientCreate()
	{
		SetTimer(Handle(), 1, 100, NULL);
		SetWindowTheme(Handle(), L"", L"");
	}

	VOID Window::OnNonClientActivate(BOOL active)
	{
		m_IsActive = active;
	}

	VOID Window::OnNonClientPaint(HRGN region)
	{
		HDC hdc = GetDCEx(m_Handle, region, DCX_WINDOW | DCX_INTERSECTRGN | DCX_USESTYLE);

		RECT rect;
		GetWindowRect(Handle(), &rect);

		SIZE size = SIZE{ rect.right - rect.left, rect.bottom - rect.top };

		HBITMAP hbmMem = CreateCompatibleBitmap(hdc, size.cx, size.cy);
		HANDLE hOld = SelectObject(hdc, hbmMem);

		HBRUSH brush = CreateSolidBrush(RGB(46, 46, 46));
		FillRect(hdc, new RECT{ 0, 0, size.cx, size.cy }, brush);
		DeleteObject(brush); // deallocate memory

		ReleaseDC(Handle(), hdc);
	}
}


