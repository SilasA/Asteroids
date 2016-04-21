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


#ifndef GAME_H
#define GAME_H

#define _G Game::

#include "ConfigHandler.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Laser.h"
#include "Player.h"

//
//
//
//
class Game : public ConfigHandler
{
private:

	Ship ship{ "assets\ship.png", 200 };
	std::vector<Asteroid>* asteroids;
	std::vector<Laser>* shots;

	sf::Texture bg;
	sf::Sprite bgSprite;

	Player player{ 3 };

	bool gameover = false;

public:

	void createAsteroids();

	void gameLoop();

	Game();

};


#endif /* GAME_H */