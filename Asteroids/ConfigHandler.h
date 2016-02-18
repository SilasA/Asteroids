//

#ifndef CONFIGHANDLER_H
#define CONFIGHANDLER_H

#include <string>
#include <iostream>
#include <fstream>

#include "Log.h"

class ConfigHandler : public Log
{
private:

	std::ifstream configFile;

public:

	// Configuration variables here.

	ConfigHandler(std::string& dir);
	~ConfigHandler();

};


#endif /* CONFIGHANDLER_H */