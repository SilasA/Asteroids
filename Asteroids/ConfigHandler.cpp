///////////////////////////////////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
///				mixed with an equally popular game Galaga.
/// version 0.0.1
/// author: Silas Agnew <agnewsilas@gmail.com>
///
/// Created for a Showcase Project for CACC Programming and Mobile Applications
/// class with SFML - Simple and Fast Multimedia Library
/// 
/// This software can be used freely as open-source software with proper
/// representation of the author and following SFML's terms of use.
///
/// Improper representation may result in the following
/// 
///	- Disembowelment / forced Seppuku
///	- Smashing of the culprit's knees, ankles, or other vital joints
///	- Severing of the culprit's limb(s)
///	- RKO
/// - 360 no-scope(s)
///
/// Beware: These punishments will be enforced 95% of the time 35% of the time
///
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ConfigHandler.h"


// Static variable instantiation
std::ifstream* _CH configFile;
unsigned int _CH winHeight;
unsigned int _CH winWidth;
unsigned int _CH frameRate;
float _CH shipMaxSpeed;


ConfigHandler::ConfigHandler()
{
}


ConfigHandler::~ConfigHandler()
{
	delete _CH configFile;
}


void ConfigHandler::setConfig()
{
	_CH winHeight = std::stoi(findKeyWord("winHeight"));
	_CH winWidth = std::stoi(findKeyWord("winWidth"));
	_CH frameRate = std::stoi(findKeyWord("frameRate"));

	configFile->close();
}


std::string ConfigHandler::findKeyWord(const std::string& keyword)
{
	std::string line;
	std::string key;
	std::string value;
	int length = keyword.length();

	while (std::getline(*_CH configFile, line))
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