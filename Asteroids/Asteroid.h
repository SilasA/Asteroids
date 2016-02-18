//

#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Error.h"
#include "Animation.h"
#include "Log.h"


enum class Size { SMALL, NORMAL, LARGE };


class Asteroid : public Animation, public Log
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