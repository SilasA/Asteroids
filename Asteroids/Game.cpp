//
#include "Game.h"


void Game::createAsteroids()
{	
					// TODO: Temp number.
	for (int i = 0; i < 6; i++)
		asteroids.push_back(Asteroid{ "Asteroid_spritesheet_normal.png" });

	for (int i = 0; i < 2; i++)
		asteroids.push_back(Asteroid{ "Asteroid_spritesheet_small.png" });

	for (int i = 0; i < 2; i++)
		asteroids.push_back(Asteroid{ "Asteroid_spritesheet_large.png" });

}