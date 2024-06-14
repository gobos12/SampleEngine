#include "Engine.h"
#include "Simulation.h"
#include "GameEngine/SplashScreen.h"

Engine::Simulation::Simulation() : Win32::Window(L"MainApplication", NULL)
{

}

Engine::Simulation::~Simulation()
{

}

VOID Engine::Simulation::PreInitialize()
{
	Logger::PrintDebugSeperator();
	Logger::PrintLog(L"Application Starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time %s\n", Time::GetDateTimeString());
	Logger::PrintLog(L"Engine Mode: %s\n", GameEngine::EngineModeToString().c_str());
	Logger::PrintDebugSeperator();

	SplashScreen::Open();

	Win32::Window::RegisterNewClass();
	Win32::Window::Initialize();
}


LRESULT Engine::Simulation::MessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	}

	return Window::MessageHandler(hWnd, msg, wParam, lParam);
}