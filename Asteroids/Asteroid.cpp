
#include "Asteroid.h"


Asteroid::Asteroid(std::string& dir) 
{
	if (!tex.loadFromFile(dir)) err(0, dir);
}