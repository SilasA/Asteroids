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

#include <SFML\Graphics.hpp>
#include "ConfigHandler.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Laser.h"
#include "Player.h"
#include "Controls.h"
#include "GUI.h"

//
//
//
//
class Game : public ConfigHandler
{
public:

	Ship ship{ ".\\assets\\ship.png", 200 };
	std::vector<Asteroid> asteroids;
	std::vector<Laser>* shots;

	sf::Texture bg;
	sf::Sprite bgSprite;

	GUI gui;

	Player player{ 3, 100 };

	bool gameover = false;

	void update();

public:

	void createAsteroids();
	
	template<class T> // Acting as ProgramMain::mode
	void gameLoop(sf::RenderWindow* window, T* mode);

	void draw(sf::RenderWindow* window);

	Game();
};


#endif // GAME_H