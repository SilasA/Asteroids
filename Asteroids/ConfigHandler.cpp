//

#include "ConfigHandler.h"


ConfigHandler::ConfigHandler(std::string& dir)
{
	configFile.open(dir);
	writeFileFoundLog(dir, configFile.is_open());
}


ConfigHandler::~ConfigHandler()
{
	configFile.close();
}