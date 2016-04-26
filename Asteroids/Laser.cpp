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
#include "Laser.h"

#define _L Laser::


_L Laser()
{
	_PROGRAM_DIR(_dir);

	if (!tex.loadFromFile(std::string(_dir) + "\\assets\\slider.png",
		sf::IntRect{ 0, 0, 5, 10 }))
		Logger::writeLog(1, "Laser", "unable to load texture");
	else
		Logger::writeLog(2, "Laser", "loaded texture");

	tex.setRepeated(true);
	sprite.setTexture(tex);
}


void _L move(float offset)
{
	sprite.move(sf::Vector2f{ 0, offset });
}
