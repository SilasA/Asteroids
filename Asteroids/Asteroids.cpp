///////////////////////////////////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
//				mixed with an equally popular game Galaga.
// version 0.0.1
// author: Silas Agnew <agnewsilas@gmail.com>
//
// Created for a Showcase Project for CACC Programming and Mobile Applications
// class with SFML - Simple and Fast Multimedia Library
// 
// This software can be used freely as open-source software with proper
// representation of the author and following SFML's terms of use.
//
// Improper representation may result in the following
// 
//	- Disembowelment / forced Seppuku
//	- Smashing of the culprit's knees, ankles, or other vital joints
//	- Severing of the culprit's limb(s)
//	- RKO
//  - 360 no-scope(s)
//
// Beware: These punishments will be enforced 95% of the time 35% of the time
//
///////////////////////////////////////////////////////////////////////////////
#include "Utilities\Logger.h"
#include <SFML\Graphics.hpp>

#include "ResourceHandler.h"
#include "Game.h"
#include "GameMenuState.h"

#define _APPNAME_ "A Gam"
#define _APPVERSION_ "0.0.1"

int main(int argc, char* argv[])
{
	Logger::AddLogger("log", "./logs/asteroids_log.txt");
	Logger::WriteLog(LogType::kALL, "APP", "Application: " _APPNAME_);
	Logger::WriteLog(LogType::kALL, "APP", "Version:" _APPVERSION_);

	ResourceHandler::Initialize("./assets/");

	int ret;

	try
	{
		ret = Game().Main();
	}
	catch (std::exception ex)
	{
		Logger::WriteLog(LogType::kERROR, "MAIN", ex.what());
	}

	return ret;
}