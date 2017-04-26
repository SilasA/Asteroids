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
#ifndef GAME_H
#define GAME_H

#include <SFML\Graphics.hpp>
#include <stack>
#include <memory>

#include "Object.h"

class GameState;

// Summary:
//
//
class Game : public Object
{
private:
    std::shared_ptr<sf::RenderWindow> m_window;

    std::stack<GameState*> m_states;

    bool m_statePopped = false;
    bool m_stateChanged = false;
    bool m_isResuming = false;

public:
    Game();

    bool IsEmpty() { return m_states.empty(); }
    bool IsStateChanged(bool reset = false);

    // If needed
    std::shared_ptr<sf::RenderWindow> GetWindow() { return m_window; }

    int Main();

    void Push(GameState* gameState);
    void Pop();
    GameState* Peek();
};

#endif // GAME_H