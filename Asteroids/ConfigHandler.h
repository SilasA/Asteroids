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

#ifndef CONFIGHANDLER_H
#define CONFIGHANDLER_H

#include <string>
#include <iostream>
#include <fstream>
#include <string>

// \brief Handles the configuration file (a text or binary file) and 
//		gathers its information.
//	
//	This is used as a parent class to most objects in the game, sharing 
//	its variables to configure the program to the given specifications.
//
//	File format example:
//		<keyword>=<value>
//		winWidth=800
//		winHeight=800
class ConfigHandler
{
	
private:

	

protected:

	static std::ifstream configFile;

	// Window info
	static unsigned int winHeight;
	static unsigned int winWidth;
	static unsigned int frameRate;

	// Ship
	static float shipMaxSpeed;

	// \brief Gathers the configuration info and stores it in the respective 
	//		variable.
	static void setConfig();

	// \brief Searches the configuration file for keywords.
	// \param keyword The word to search for
	// \returns The respective value in string form to be converted to 
	//		the correct type.
	static std::string findKeyWord(const std::string& keyword);

public:

	ConfigHandler();
	~ConfigHandler();
	
};


#endif /* CONFIGHANDLER_H */