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

#include "stdafx.h"
#include "Game.h"


_G Game()
{
	_PROGRAM_DIR(_dir);

	// Sprite Initialization
	if (!bg.loadFromFile(std::string(_dir) + "\\assets\\background.png"))
		Logger::writeLog(1, "Game", "unable to load BG texture");
	else
		Logger::writeLog(2, "Game", "loaded BG texture");

	bg.setRepeated(true);
	bgSprite.setTexture(bg);
	bgSprite.setTextureRect(sf::IntRect{ 0, 0,
		(int)winWidth, (int)winHeight * 3 });
	
	createAsteroids();
}


void _G createAsteroids()
{	
	for (int i = 0; i < 6; i++)
		asteroids.push_back(Asteroid{ std::string(_dir) +
		"\\assets\\Asteroid_spritesheet_normal.png", 50 });

	for (int i = 0; i < 2; i++)
		asteroids.push_back(Asteroid{ std::string(_dir) +
		"\\assets\\Asteroid_spritesheet_small.png", 25 });

	for (int i = 0; i < 2; i++)
		asteroids.push_back(Asteroid{ std::string(_dir) +
		"\\assets\\Asteroid_spritesheet_large.png", 100 });

	// Print the total amount of asteroids
	Logger::writeLog(2, "Asteroid", std::to_string(
		asteroids[0].getAsteroidTotal()) + "");
}


void _G draw(sf::RenderWindow* window)
{
	window->draw(bgSprite);
	window->draw(ship.getSpriteForDraw());
	for (auto asteroid : asteroids)
		window->draw(asteroid.getSpriteForDraw());
}


void _G update()
{
	// GUI
	gui.UISliders[0].setValue(player.getPlayerHP());

	// Objects

}


template<class T>
void _G gameLoop(sf::RenderWindow* window, T* mode)
{
	while (!gameover && window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Esc // Exit to menu
			if (_KeyPressed(_ESC))
			{
				*mode = (T)1;
				return;
			}

			// Left
			if (_KeyPressed(_LEFT_KB) || _KeyPressed(_LEFT_AR))
			{
				
			}

			// Right
			if (_KeyPressed(_RIGHT_KB) || _KeyPressed(_RIGHT_AR))
			{

			}

			// Up
			if (_KeyPressed(_UP_KB) || _KeyPressed(_UP_AR))
			{

			}

			// Down
			if (_KeyPressed(_DOWN_KB) || _KeyPressed(_DOWN_AR))
			{

			}

			// Shoot (space)
			if (_KeyPressed(_SPACE))
			{

			}

			// Key Release
			if (event.type == _KEY_RELEASED &&
				event.key != _SPACE)
			{
				ship.setAccelRate(0.f);
			}
		}

		// Updating objects
		update();

		// Drawing
		draw(window);

		if (player.getPlayerLives() < 0) 
			gameover = true;
	}
}