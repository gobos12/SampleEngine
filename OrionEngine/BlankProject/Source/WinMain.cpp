#include "pch.h"

/* GLOBAL VARIABLES */
WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];
INT WindowWidth;
INT WindowHeight;


void InitVariables()
{
	wcscpy_s(WindowClass, TEXT("FirstClass"));
	wcscpy_s(WindowTitle, TEXT("My First Window"));

	WindowWidth = 1366;
	WindowHeight = 768;
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

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WinProc;

	return wcex;
}

/* MAIN */
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	/* Initialize Global Variables */
	InitVariables();

	/* Create Window Class */
	WNDCLASSEX wcex = RegisterWindowClass();
	RegisterClassEx(&wcex);

	/* Create and Display Window*/
	if (!InitWindow()) {
		MessageBox(0, L"Failed to Create Window!", 0, 0);
		return 0;
	}

	/* Listen for Message events */
	MSG msg{ 0 };
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}
