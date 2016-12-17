///////////////////////////////////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
//				mixed with an equally popular game Galaga.
// version 0.0.1
// author: Silas Agnew <agnewsilas@gmail.com>
//
// Created for a Showcase Project for CACC Programming and Mobile Applications
// class with SFML - Simple and Fast Multimedia Library
// 
// This software can be used freely as open-source software with proper
// representation of the author and following SFML's terms of use.
//
// Improper representation may result in the following
// 
//	- Disembowelment / forced Seppuku
//	- Smashing of the culprit's knees, ankles, or other vital joints
//	- Severing of the culprit's limb(s)
//	- RKO
//  - 360 no-scope(s)
//
// Beware: These punishments will be enforced 95% of the time 35% of the time
//
///////////////////////////////////////////////////////////////////////////////
#ifndef GAME_MENU_STATE_H
#define GAME_MENU_STATE_H

#include "GameState.h"

// Summary:
//
//
class GameMenuState : public GameState
{
private:


public:
	GameMenuState(Game* game);

	virtual void InitResources() override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Update() override;
	virtual void SaveState() override;
	virtual void LoadState() override;
};

#endif // GAME_MENU_STATE_H