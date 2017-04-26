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
#include "GameStateStart.h"


GameStateStart::GameStateStart(Game* game)
{
	this->game = game;
}


GameStateStart::~GameStateStart()
{
}


void GameStateStart::loadgame()
{

}


void GameStateStart::draw()
{

}


void GameStateStart::update()
{

}


void GameStateStart::handleInput()
{
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case _MOUSE_PRESSED:
		case _KEY_PRESSED:
			presses(&event);
			break;
		case _MOUSE_MOVED:
			movements(&event);
			break;
		case _WIN_RESIZED:
			resize(&event);
			break;
		case _WIN_CLOSED:
			game->window.close();
			break;
		default:
			break;
		}
	}
}