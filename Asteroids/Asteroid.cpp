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
#include "Asteroid.h"


int _AST asteroidTotal = 0;


_AST Asteroid(const std::string& dir, int size)
	: size((Size)size),
	Animation(
	new std::vector<sf::IntRect>{
		sf::IntRect{ 0, 0, size, size },
		sf::IntRect{ size, 0, size, size },
		sf::IntRect{ size * 2, 0, size, size },
		sf::IntRect{ size * 3, 0, size, size } },
	new std::vector<sf::IntRect>{
		sf::IntRect{ 0, size, size, size },
		sf::IntRect{ size, size, size, size },
		sf::IntRect{ size * 2, size, size, size },
		sf::IntRect{ size * 3, size, size, size }},
	true,
	sf::milliseconds(250))
{
	asteroidTotal++;

	if (!tex.loadFromFile(dir))
		Logger::writeLog(1, "Asteroid" +
		std::to_string(asteroidTotal), "unable to load texture.");

	sprite.setTexture(tex);
	sprite.setTextureRect(nFrames[0]);
}


float _AST getLeft(sf::Vector2f& origin)
{
	return sprite.getPosition().x - origin.x; 
}


float _AST getRight(sf::Vector2f& origin)
{
	return sprite.getPosition().x + nFrames[getCurIndex()].width - origin.x;
}


float _AST getTop(sf::Vector2f& origin)
{
	return sprite.getPosition().y - origin.y;
}


float _AST getBottom(sf::Vector2f& origin)
{
	return sprite.getPosition().y + nFrames[getCurIndex()].height - origin.y;
}