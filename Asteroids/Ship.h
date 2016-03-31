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

#ifndef SHIP_H
#define SHIP_H

#include <SFML\Graphics.hpp>

#include "Animation.h"

#define _S Ship::

class Ship : public Animation
{
private:

	// Current velocity of the ship.
	sf::Vector2f velocity;


public:
	
	// \returns The current velocity of the ship.
	sf::Vector2f getVelocity() { return velocity; }

	//
	void update();

	//
	Ship();

};

#endif /* SHIP_H */