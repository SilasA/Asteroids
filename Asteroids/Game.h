/////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
// Created by Silas Agnew with SFML - Simple and Fast Multimedia Library
// 
// This software can be used freely as open-source software with proper
/////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
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
///  - 360 no-scope(s)
///
/// Beware: These punishments will be enforced 95% of the time 35% of the time
///
/////////////////////////////////////////////////


#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include "Asteroid.h"

class Game
{
private:

	Ship ship;
	std::vector<Asteroid> asteroids;

public:

	void createAsteroids();

	Game();

};


#endif /* GAME_H */