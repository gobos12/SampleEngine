#include "Engine.h"
#include "IApplication.h"
#include "Common/CmdLineArgs.h"
#include "GameEngine/SplashScreen.h"

extern Win32::IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();

	PerGameSettings gameSettings;
	EntryApp->SetupPerGameSettings();

	CmdLineArgs::ReadArguments(); 

	Logger logger;
	
	EntryApp->PreInitialize();
	EntryApp->Initialize();

	MSG msg{ 0 };
	while (msg.message != WM_QUIT) 
	{
		// If there are Window messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) { 
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} 
		else {
			EntryApp->Update();
		}
	}

	return 0;
}