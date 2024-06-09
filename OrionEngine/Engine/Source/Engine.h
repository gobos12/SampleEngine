#pragma once

#ifdef WIN32
	#include <Windows.h>
#endif // WIN32

#ifdef BUILD_DLL
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)  // hInstance callback

#include "Common/Logger.h"
#include "Common/Time.h"
#include "Core/PerGameSettings.h"