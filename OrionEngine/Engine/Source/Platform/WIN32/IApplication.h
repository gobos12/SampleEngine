#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class ENGINE_API IApplication
{

public:
	/* Application Constructor */
	IApplication();

	/* Application Deconstructor*/
	virtual ~IApplication() {};

public: 
	/* Called to initialize application */
	virtual VOID Initialize() = 0;

	/* Game Loop - called on a loop while application is running */
	virtual VOID Update() = 0;

};

IApplication* EntryApplication();