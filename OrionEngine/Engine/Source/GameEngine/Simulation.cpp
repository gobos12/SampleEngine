#include "Engine.h"
#include "Simulation.h"
#include "GameEngine/SplashScreen.h"

Engine::Simulation::Simulation()
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
}
