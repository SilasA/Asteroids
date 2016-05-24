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
#include "Logger.h"

#define _LOG Logger::

std::fstream _LOG fLog{ "log.txt", std::ios::out };


std::string _LOG findLogTypeTag(int type)
{
	std::string typeStr;

	switch (type)
	{
	case (int)Log_Type::Error:
		typeStr = "[ERROR] ";
		break;
	case (int)Log_Type::Warning:
		typeStr = "[WARNING] ";
		break;
	case (int)Log_Type::Info:
		typeStr = "[INFO] ";
		break;
	case (int)Log_Type::Custom:
	default:
		typeStr = "[CUSTOM] ";
		break;
	}

	return typeStr;
}


void _LOG writeLog(int type, std::string tag, std::string content)
{
	if (!_LOG fLog.is_open()) return;

	_LOG fLog << _LOG findLogTypeTag(type) << tag << ": " << content <<
		std::endl;
}


void _LOG writeLog(std::string tag, std::string content)
{
	if (!_LOG fLog.is_open()) return;

	_LOG fLog << _LOG findLogTypeTag((int)Log_Type::Custom) << tag << ": " <<
		content << std::endl;
}