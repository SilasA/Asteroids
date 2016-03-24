//
#include "stdafx.h"
#include "ConfigHandler.h"


ConfigHandler::ConfigHandler()
{

}


ConfigHandler::~ConfigHandler()
{
}


void ConfigHandler::setConfig()
{
	winHeight = std::stoi(findKeyWord("winHeight"));
	winWidth =	std::stoi(findKeyWord("winWidth"));
	frameRate = std::stoi(findKeyWord("framRate"));

	configFile.close();
}


std::string& ConfigHandler::findKeyWord(const std::string& keyword)
{
	std::string line;
	std::string key;
	std::string value;
	int length = keyword.length();

	while (std::getline(configFile, line))
	{
		// Separate the keyword from the line
		key = line.substr(0, length - 1); 

		// Find the value of the specified keyword
		if (key == keyword)
		{
			value = line.substr(length + 1, line.length() - 1);
			break;
		}
	}
	return value;
}