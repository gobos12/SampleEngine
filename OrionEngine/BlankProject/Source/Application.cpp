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

VOID Application::Initialize()
{
	MessageBox(0, L"Application initalized!", 0, 0);
}

VOID Application::Update()
{
	MessageBox(0, L"Loop...", 0, 0);
}
