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

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <iostream>

// \brief The types of logs used in the logging file.
static enum class Log_Type : int { ERROR, WARNING, INFO, CUSTOM };


//
//
//
//
//
class Logger
{
private:

	static std::fstream fLog;

	static std::string findLogTypeTag(Log_Type type);

public:
	
	// \brief Write a log to the log file.
	//	
	// \param type	  The type of log as defined in Log_Type
	// \param tag	  The log's tag usually indicating where the log was written
	//				  from
	// \param content The content of the log
	static void writeLog(Log_Type type, std::string tag, std::string content);

	// \brief Write a custom log that doesn't fit into any of the Log_Type
	//		categories
	//
	// \param tag	  The log's tag usually indicating where the log was written
	//				  from
	// \param content The content of the log
	static void writeLog(std::string tag, std::string content);
	

};


#endif // LOGGER_H