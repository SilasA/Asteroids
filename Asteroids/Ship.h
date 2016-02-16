//

#ifndef SHIP_H
#define SHIP_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Error.h"

class Ship : public Animation, public Error
{
private:

	// Current velocity of the ship.
	sf::Vector2f velocity;


public:
	
	// Returns the velocity of the ship.
	sf::Vector2f getVelocity() { return velocity; }

	void update();

	//
	Ship();

};

#endif /* SHIP_H */