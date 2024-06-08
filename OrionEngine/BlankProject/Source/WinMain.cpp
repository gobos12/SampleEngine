#include "pch.h"
/* ------------------------------------------------- */
/* Title: WinMain.cpp								 */
/* Author: Orion Dobos								 */
/* ------------------------------------------------- */


/* ------------------------------------------------- */
/* Global Variables									 */
/* ------------------------------------------------- */
#pragma region GlobalVariables
	WCHAR		WindowClass[MAX_NAME_STRING];
	WCHAR		WindowTitle[MAX_NAME_STRING];

	INT			WindowWidth;
	INT			WindowHeight;

	HICON		hIcon;
#pragma endregion


/* ------------------------------------------------- */
/* Pre-Declarations									 */
/* ------------------------------------------------- */
#pragma region Pre-Declarations

	void				InitVariables();
	BOOL				InitWindow();
	LRESULT	CALLBACK	WinProc(HWND, UINT, WPARAM, LPARAM);
	WNDCLASSEX			RegisterWindowClass();

#pragma endregion

/* ------------------------------------------------- */
/* Operations										 */
/* ------------------------------------------------- */
#pragma region OPERATIONS
//int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
//{
//	InitVariables();
//
//	/* Create Window Class */
//	WNDCLASSEX wcex = RegisterWindowClass();
//	RegisterClassEx(&wcex);
//
//	/* Create and Display Window*/
//	if (!InitWindow()) {
//		MessageBox(0, L"Failed to Create Window!", 0, 0);
//		return 0;
//	}
//
//	/* Listen for Message events */
//	MSG msg{ 0 };
//	while (msg.message != WM_QUIT) {
//		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//
//	return 0;
//}
#pragma endregion

/* ------------------------------------------------- */
/* Functions										 */
/* ------------------------------------------------- */
#pragma region Functions

void InitVariables()
{
	LoadString(HInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);

	WindowWidth = 1366;
	WindowHeight = 768;

	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

BOOL InitWindow()
{
	HWND hWnd = CreateWindow(
		WindowClass,
		WindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		WindowWidth,
		WindowHeight,
		nullptr,		// parent window
		nullptr,		// menu window
		HInstance(),
		nullptr			// give specific instructions to window at runtime to do special things
	);

	if (!hWnd) {
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);
	return 1;
}

LRESULT	CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

WNDCLASSEX RegisterWindowClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;

	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WinProc;

	return wcex;
}
#pragma endregion