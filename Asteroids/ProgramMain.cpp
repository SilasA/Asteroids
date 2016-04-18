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
#include "ProgramMain.h"


_PM ProgramMain(const std::string& configDir)
{
	_CH configFile->open(configDir);
	// No file to specify so set to null
	logFile = nullptr;

	isLog = false;
	//logger = std::thread(&_PM log);
	
	// Find data
	findSaves();



	setConfig();

}

_PM ProgramMain(std::string& configDir, std::string& logDir)
{
	_CH configFile->open(configDir);

	isLog = true;
	//logger = std::thread(&_PM log);
}


void _PM pgmMain()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
	}
}