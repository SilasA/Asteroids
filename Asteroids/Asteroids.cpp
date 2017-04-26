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
#include <SFML\Graphics.hpp>

#include "Utilities\Logger.h"
#include "Resources.h"
#include "Game.h"
#include "GameMenuState.h"
#include "Persistance.h"

#include <pugixml.hpp>

#define _APPNAME_ "A Gam"
#define _APPVERSION_ "0.0.1"

int main(int argc, char* argv[])
{
    pLog log = Logger::GetInstance("./Logs/");
    log->AddLogger("log", "./logs/asteroids_log.txt");
    log->WriteLog(LogType::kALL, "APP", "Application: " _APPNAME_);
    log->WriteLog(LogType::kALL, "APP", "Version:" _APPVERSION_);

    int ret;

    try
    {
        ret = Game().Main();
    }
    catch (std::exception& ex)
    {
        log->WriteLog(LogType::kERROR, "MAIN", ex.what());
    }

    return ret;
}