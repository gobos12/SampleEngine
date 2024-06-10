#pragma once

#include <string>

class ENGINE_API Logger
{
private:
	static Logger* instance;
public:
	static Logger* Singleton() { return instance; }
public:
	Logger();
	~Logger();

	static VOID PrintLog(const WCHAR* fmt, ...);

	static std::wstring LogDirectory();

	static std::wstring LogFile();

	/* Print a line of '-' char's with no time string */
	static VOID PrintDebugSeperator();

	/* mTAIL is a debug program that prints log statements while the program is running. */

	/* Check to see if MTail is already running */
	static BOOL IsMTailRunning();

	/* Start MTail Application */
	static VOID StartMTail();
};