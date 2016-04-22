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
	bg.loadFromFile(".\\assets\\background.png");
	bg.setRepeated(true);
	bgSprite.setTexture(bg);
	bgSprite.setTextureRect(sf::IntRect{ 0, 0,
		(int)winWidth, (int)winHeight * 3 });

	createAsteroids();


}


void _G createAsteroids()
{	
	for (int i = 0; i < 6; i++)
		asteroids->push_back(Asteroid{ ".\\assets\\Asteroid_spritesheet_normal.png", 50 });

	for (int i = 0; i < 2; i++)
		asteroids->push_back(Asteroid{ ".\\assets\\Asteroid_spritesheet_small.png", 25 });

	for (int i = 0; i < 2; i++)
		asteroids->push_back(Asteroid{ ".\\assets\\Asteroid_spritesheet_large.png", 100 });
	// Asteroid Total: 10
}


void _G gameLoop()
{
	while (!gameover)
	{


		if (player.getPlayerLives() < 0) 
			gameover = true;
	}
}