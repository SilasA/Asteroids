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

#ifndef LASER_H
#define LASER_H

#include <sstream>
#include <string>
#include "SFML\Graphics.hpp"

// \brief
//
//
//
class Laser
{
private:

	sf::Texture tex;
	sf::Sprite sprite;

public:

	// \brief Moves the laser on Y axis only
	// \param offset Change in position in pixels
	void move(float offset);

	// \brief
	Laser();

};


#endif // LASER_H