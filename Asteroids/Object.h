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
#ifndef OBJECT_H
#define OBJECT_H

#include "Utilities\Logger.h"

#include <string>

// Summary:
//	Base class for all objects in the application
class Object
{
private:
    std::string m_id;

protected:
    pLog m_log;

public:
    Object(const std::string& id) :
        m_id(id), m_log(Logger::GetInstance())
    {
    }

    std::string Id() { return m_id; }
};

#endif // OBJECT_H
