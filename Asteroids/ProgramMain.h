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

#ifndef PROGRAMMAIN_H
#define PROGRAMMAIN_H

#include "ConfigHandler.h"
#include "GameSave.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <time.h>

#define _PM ProgramMain::

//
//
//
//
class ProgramMain : public ConfigHandler, public GameSave
{
private:

	// The window the entire program is run through
	sf::RenderWindow window{ sf::VideoMode{ winWidth, winHeight }, 
		"Asteroids!" };



	///////////////////////////////////////////////////////////////////////////
	// Logging
	///////////////////////////////////////////////////////////////////////////

	// If the thread is to log (false may be caused by a failure to find the
	// logging file)
	bool isLog;
	
	// The thread that is constantly looping and writing to a log file
	std::thread logger;

	// The file used to log information
	std::ofstream* logFile;

	// \brief The function that logs important information every x period
	//		of time.
	// \param logDir The directory of the log file to write to
	void log();// std::string logDir);

	



public:

	//
	void pgmMain();

	//
	ProgramMain(const std::string& configDir);

	//
	ProgramMain(std::string& configDir, std::string& logDir);

};

#endif // PROGRAMMAIN_H