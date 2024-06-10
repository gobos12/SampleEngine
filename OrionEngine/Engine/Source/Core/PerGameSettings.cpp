#include "Engine.h"

PerGameSettings* PerGameSettings::instance;

PerGameSettings::PerGameSettings()
{
	instance = this;

	wcscpy_s(instance->m_GameName, L"undefined");
	wcscpy_s(instance->m_ShortName, L"undefined");
	wcscpy_s(instance->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
	wcscpy_s(instance->m_SplashURL, L"..Engine\\Content\\Images\\Splash.bmp");
}

PerGameSettings::~PerGameSettings()
{

}
