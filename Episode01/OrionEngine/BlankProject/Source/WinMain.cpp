#include <windows.h>

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)  // hInstance callback

WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

INT WindowWidth;
INT WindowHeight;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	/* Initialize Global Variables */

	wcscpy_s(WindowClass, TEXT("FirstClass"));
	wcscpy_s(WindowTitle, TEXT("My First Window"));

	WindowWidth = 1366;
	WindowHeight = 768;

	/* Create Window Class */

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
	wcex.lpfnWndProc = DefWindowProc;

	RegisterClassEx(&wcex);

	/* Create and Display Window*/

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
		MessageBox(0, L"Failed to Create Window!", 0, 0);
		return 0;
	}
	
	ShowWindow(hWnd, SW_SHOW);

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