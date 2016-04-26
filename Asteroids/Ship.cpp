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
#include "Ship.h"

#include <SFML\Graphics.hpp>


_S Ship(const std::string& dir, unsigned int fLimit) 
	: Animation(
		new std::vector<sf::IntRect> { sf::IntRect{ } },
		new std::vector<sf::IntRect> { 
			sf::IntRect{ 0, 100, 100, 100 }, 
			sf::IntRect{ 100, 100, 100, 100 } },
		true,
		sf::milliseconds(250))
{
	if (!tex.loadFromFile(dir))
		Logger::writeLog(1, "Ship", "unable to load texture.");
	else
		Logger::writeLog(2, "Ship", "loaded texture");

	shipSprite.setTexture(tex);
	shipSprite.setTextureRect(nFrames[0]);

	this->fLimit = fLimit;
}


void _S setFLimit(unsigned int fLimit)
{
	this->fLimit = fLimit;
}


void _S accelerate(float setSpeed)
{
	velocity.x = setSpeed;
}


void _S update()
{
	shipSprite.move(shipSprite.getPosition() + velocity);
}