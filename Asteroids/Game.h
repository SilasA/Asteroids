#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include "Asteroid.h"
#include "Error.h"

class Game : public Error
{
private:

	Ship ship;
	std::vector<Asteroid> asteroids;


};


#endif /* GAME_H */