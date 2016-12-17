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

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <Logger.h>
#include "Game.h"
#include "Controls.h"
#include "Object.h"

#include <string>

// Global function for loading a texture from a file
inline sf::Texture load_texture(std::string dir);

// Summary:
//
//
class GameState : public Object
{
protected:
	Game* m_game;

public:
	GameState(Game* game, const std::string& id) :
		Object(id),
		m_game(game)
	{
	}

	// Must Implement
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Update() = 0;
	virtual void InitResources() = 0;
	virtual void SaveState() = 0;
	virtual void LoadState() = 0;

	// May Implement
	virtual void Presses(sf::Event& event) {}
	virtual void Releases(sf::Event& event) {}
	virtual void WindowResized(sf::Event& event) {}
	virtual void ControlMoved(sf::Event& event) {}
	virtual void ControlActions(sf::Event& event) {}
};

inline sf::Texture load_texture(std::string dir)
{
	sf::Texture tex;
	if (!tex.loadFromFile(dir))
		Logger::WriteLog(LogType::kWARNING,
			"INIT", "unable to load texture: " + dir, "log");
	else
		Logger::WriteLog(LogType::kINFO,
			"INIT", "loaded texture: " + dir, "log");
	return tex;
}

#endif // GAME_STATE_H