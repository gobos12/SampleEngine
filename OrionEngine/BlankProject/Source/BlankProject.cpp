/* SAMPLE APPLICATION FILE */
/*		DO NOT EDIT		   */

#include "BlankProject.h"
#include "GameEngine/Simulation.h"
#include "Platform/Win32/WinEntry.h"

class BlankProject : public Engine::Simulation
{

public:
	/* BlankProject Constructor */
	BlankProject() { }

	/* BlankProject Deconstructor*/
	~BlankProject() { }

public:
	VOID SetupPerGameSettings();

	/* Called to initialize BlankProject */
	VOID Initialize() { }

	/* Game Loop - called on a loop while BlankProject is running */
	VOID Update() { }

};

ENTRYAPP(BlankProject)

VOID BlankProject::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashURL(IDS_SPLASHURL);
}