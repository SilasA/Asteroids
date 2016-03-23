///////////////////////////////////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
///				mixed with an equally popular game Battlestar Galactica.
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

#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Animation.h"

enum class Size { SMALL, NORMAL, LARGE };


class Asteroid : public Animation
{
private:

	sf::Texture tex;
	sf::Sprite sprite;

	// The size of the asteroid.
	Size size;

	// Returns the respective sides relative to the origin.
	float getLeft(sf::Vector2f& origin);
	float getRight(sf::Vector2f& origin);
	float getTop(sf::Vector2f& origin);
	float getBottom(sf::Vector2f& origin);

public:

	Asteroid(const std::string& dir);
	
};


#endif /* ASTEROID_H */