//
#include "stdafx.h"
#include "Asteroid.h"


Asteroid::Asteroid(const std::string& dir) 
{
}


float Asteroid::getLeft(sf::Vector2f& origin)
{
	return sprite.getPosition().x - origin.x; 
}


float Asteroid::getRight(sf::Vector2f& origin)
{
	return sprite.getPosition().x + nFrames[getCurIndex()].width - origin.x;
}


float Asteroid::getTop(sf::Vector2f& origin)
{
	return sprite.getPosition().y - origin.y;
}


float Asteroid::getBottom(sf::Vector2f& origin)
{
	return sprite.getPosition().y + nFrames[getCurIndex()].height - origin.y;
}