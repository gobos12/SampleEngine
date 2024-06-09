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
};