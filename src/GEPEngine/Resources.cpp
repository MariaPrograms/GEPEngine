#include "Resources.h"
#include "Exception.h"
#include "Core.h"
#include <iostream>

#if _WIN32
#include <windows.h>
#endif


Resources::Resources(std::shared_ptr<Core> _core)
{
	core = _core;

#if _WIN32

#ifdef NDEBUG
	char strExePath[MAX_PATH];
	GetModuleFileName(NULL, strExePath, MAX_PATH);
	std::string fullPath = strExePath;
	std::string basename = fullPath.substr(0, fullPath.find_last_of("\\"));

	basePath = basename;
#else
	basePath = "..";

#endif

#elif defined (__unix__) || defined(__APPLE__) || defined(__linux__)
	command = "cd `dirname \\`which " + std::string(argv[0]) + "\\``; cd ..; pwd | tr -d '\n'";

#endif

	
}
