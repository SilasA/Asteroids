//

#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Error.h"
#include "Animation.h"


class Asteroid : public Animation, public Error
{
private:

	sf::Texture tex;
	sf::Sprite sprite;

	// Returns the respective sides relative to the origin.
	float getLeft(sf::Vector2f& origin);
	float getRight(sf::Vector2f& origin);
	float getTop(sf::Vector2f& origin);
	float getBottom(sf::Vector2f& origin);

public:

	Asteroid(std::string& dir);
	
};


#endif /* ASTEROID_H */