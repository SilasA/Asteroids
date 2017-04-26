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
#include "Clickable.h"

#include <memory>

// Summary:
//
//
class GameMenuState : public GameState
{
private:
    std::vector<Clickable> m_buttons;

public:
    GameMenuState(Game* game);
    ~GameMenuState();

    void InitResources() override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;
    void Update(sf::Event& event) override;
    void SaveState(std::shared_ptr<Persistance> persistance) override;
    void LoadState(std::shared_ptr<Persistance> persistance) override;
};

#endif // GAME_MENU_STATE_H