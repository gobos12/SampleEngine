#pragma once

#include "Core/CoreDefinitions.h"
#include "Core/PerGameSettings.h"

#include "GameEngine/OEngine.h"

#include "Common/Logger.h"
#include "Common/Time.h"

#ifdef WIN32
	#include "Platform/WIN32/Win32Utils.h"
	#include "Platform/WIN32/SubObject.h"
	#include "Platform/WIN32/Window.h"
	#include "Platform/WIN32/IApplication.h"
#endif
