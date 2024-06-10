#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{

}

Application::~Application()
{

}

VOID Application::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

VOID Application::Initialize()
{
	Logger::StartMTail();
	Logger::PrintLog(L"Application Loaded!!! %s, Yahoo!!", L"Blank Project");
}

VOID Application::Update()
{
	//Logger::PrintLog(L"Loop...");
}
