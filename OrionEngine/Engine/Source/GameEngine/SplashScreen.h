#pragma once

#include "Platform/Win32/Window.h"

namespace SplashScreen
{
	/* Window first opens while engine is loading up */
	VOID ENGINE_API Open();
	VOID ENGINE_API Close();
	VOID ENGINE_API AddMessage(CONST WCHAR* message);
}

class ENGINE_API SplashWindow : public Win32::Window
{
public:
	SplashWindow();
	~SplashWindow();

	virtual LRESULT MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};