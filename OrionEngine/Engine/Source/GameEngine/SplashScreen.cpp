#include "Engine.h"
#include "SplashScreen.h"
#include "Platform/Win32/Win32Utils.h"

namespace SplashScreen
{
#define WM_OUTPUTMESSAGE (WM_USER + 0X001)

	SplashWindow* m_SplashWindow = nullptr;

	VOID Open()
	{
		if (m_SplashWindow != nullptr) return;
		m_SplashWindow = new SplashWindow();
	}

	VOID Close()
	{

	}

	VOID AddMessage(const WCHAR* message)
	{
		PostMessage(m_SplashWindow->Handle(), WM_OUTPUTMESSAGE, (WPARAM)message, 0);
	}
}

SplashWindow::SplashWindow() : Win32::Window(L"SplashScreen", NULL, Win32::WindowType::POPUP)
{
	wcscpy_s(m_outputMessage, L"Splashscreen Starting...");
	Win32::Window::RegisterNewClass();
	Size(500, 600);
	Win32::Window::Initialize();
}

SplashWindow::~SplashWindow()
{

}

LRESULT SplashWindow::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	/* draw text at bottom of splash screen window */
	case WM_PAINT:
	{
		HBITMAP hbitmap;
		HDC hdc, hmemdc;
		PAINTSTRUCT ps;

		hdc = BeginPaint(hWnd, &ps);

		Win32::Utils::AddBitmap(PerGameSettings::SplashURL(), hdc);
		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(255, 255, 255));

		/* Output engine mode to screen */
		if (GameEngine::GetMode() != GameEngine::EngineMode::RELEASE)
		{
			std::wstring engineModeText = GameEngine::EngineModeToString() + L" Mode";
			SetTextAlign(hdc, TA_RIGHT);
			TextOut(hdc, Size().cx - 15, 15, engineModeText.c_str(), wcslen(engineModeText.c_str()));
		}

		SetTextAlign(hdc, TA_CENTER);

		TextOut(hdc, Size().cx / 2, Size().cy - 30, m_outputMessage, wcslen(m_outputMessage));
		EndPaint(hWnd, &ps);
	}
	break;
	/* Read from wParam and output message to window */
	case WM_OUTPUTMESSAGE:
	{
		WCHAR* msg = (WCHAR*)wParam;
		wcscpy_s(m_outputMessage, msg); 
		RedrawWindow();
		return 0;
	}
	}

	return Window::MessageHandler(hWnd, msg, wParam, lParam);
}
