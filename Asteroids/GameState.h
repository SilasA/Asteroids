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

#include "Game.h"
#include "Object.h"
#include "Utilities\Logger.h"
#include "Resources.h"
#include "Persistance.h"

#include <string>

// Global function for loading a texture from a file
inline sf::Texture load_texture(std::string dir);

// Summary:
// Base for all states of the game. This represents a mode or screen of the game.
class GameState : public Object
{
protected:
    Game* m_game;

    pRes m_res;

public:
    GameState(Game* game, const std::string& id) :
        Object(id),
        m_game(game),
        m_res(Resources::GetInstance())
    {
        m_log->WriteLog(LogType::kInfo, Id(), "Initialized", "log");
    }

    // Must Implement
    virtual void Draw(std::shared_ptr<sf::RenderWindow> window) = 0;
    virtual void Update(sf::Event& event) = 0;
    virtual void InitResources() = 0;
    virtual void SaveState(std::shared_ptr<Persistance> persistance) = 0;
    virtual void LoadState(std::shared_ptr<Persistance> persistance) = 0;

    // May Implement
    virtual void Activate() {}
    virtual void Deactivate() {}
};

inline sf::Texture load_texture(std::string dir)
{
    sf::Texture tex;
    if (!tex.loadFromFile(dir))
        Logger::GetInstance()->WriteLog(LogType::kWarning,
            "INIT", "unable to load texture: " + dir, "log");
    else
        Logger::GetInstance()->WriteLog(LogType::kWarning,
            "INIT", "loaded texture: " + dir, "log");
    return tex;
}

#endif // GAME_STATE_H