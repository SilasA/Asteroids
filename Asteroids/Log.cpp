//

#include "Log.h"

#include <iostream>
#include <string>


Log::Log()
{

}


void Log::writeLog(std::string& log)
{
	std::clog << log << std::endl;
}


void Log::writeFileFoundLog(std::string& filename, bool isFound)
{
	if (isFound)
		std::clog << "Loaded File: " << filename << std::endl;
	else
		std::clog << "Failed to Load File: " << filename << std::endl;
}


void Log::writeFileFoundLog(std::string& filename)
{
	std::clog << "Loaded File: " << filename << std::endl;
}