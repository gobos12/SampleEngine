#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{

public:
	/* Application Constructor */
	Application();

	/* Application Deconstructor*/
	~Application();

public:
	VOID SetupPerGameSettings();

	/* Called to initialize application */
	VOID Initialize();

	/* Game Loop - called on a loop while application is running */
	VOID Update();

};