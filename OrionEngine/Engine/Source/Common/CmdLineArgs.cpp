#include "Engine.h"
#include "CmdLineArgs.h"
#include <algorithm>

/* Loops through cmd line args in project (under Preferences/Config Properties/Debugging) */
VOID CmdLineArgs::ReadArguments()
{
	int argc = 0; // number of arguements
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc); 

	for (int i = 1; i < argc; ++i) // first cmd line argument is the url of the exe, so we start loop @ 1
	{
		std::wstring key = argv[i]; // very first string of argv
		if (key[0] == '-') // checks first char
		{
			key.erase(0, 1); //-mTail -> mTail
			std::transform(key.begin(), key.end(), key.begin(), ::tolower);
			ReadArgument(key.c_str());
		}
	}
}

VOID CmdLineArgs::ReadArgument(const WCHAR* argument)
{
	if (wcscmp(argument, L"mtail") == 0) Logger::StartMTail();
	if (wcscmp(argument, L"debug") == 0) GameEngine::SetMode(GameEngine::EngineMode::DEBUG);
	if (wcscmp(argument, L"editor") == 0) GameEngine::SetMode(GameEngine::EngineMode::EDITOR);
	if (wcscmp(argument, L"server") == 0) GameEngine::SetMode(GameEngine::EngineMode::SERVER);
}
