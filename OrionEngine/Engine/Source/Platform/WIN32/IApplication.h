#pragma once

#define ENTRYAPP(x) Win32::IApplication* EntryApplication() { return new x; }

namespace Win32
{
	class ENGINE_API IApplication
	{

	public:
		/* Application Constructor */
		IApplication();

		/* Application Deconstructor*/
		virtual ~IApplication() {};

	public:
		/* Called to setup per game settings */
		virtual VOID SetupPerGameSettings() = 0;

		/* Called before initializing application */
		virtual VOID PreInitialize() = 0;

		/* Called to initialize application */
		virtual VOID Initialize() = 0;

		/* Game Loop - called on a loop while application is running */
		virtual VOID Update() = 0;

	};

	IApplication* EntryApplication();
}