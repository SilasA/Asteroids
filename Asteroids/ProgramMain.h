/////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
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
/////////////////////////////////////////////////

#ifndef PROGRAMMAIN_H
#define PROGRAMMAIN_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
#include <thread>
#include <time.h>

#include "ConfigHandler.h"


class ProgramMain : public ConfigHandler
{
private:

	sf::RenderWindow window{ { winWidth, winHeight }, "Asteroids!" };

	// Logging

	// If the thread is to log (false may be caused by a failure to find the
	// logging file)
	bool isLog;

	// The file used to log information
	std::ofstream* logFile;

	// 
	//
	//
	void log(std::string& logDir);

	std::thread* logger;



public:

	void pgmMain();

	
	ProgramMain(std::string& configDir);
	ProgramMain(std::string& configDir, std::string& logDir);

};

#endif // PROGRAMMAIN_H