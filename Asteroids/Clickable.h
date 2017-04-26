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
#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

#include "GameObject.h"
#include "Game.h"

enum class ButtonState
{
    kIdle,
    kHover,
    kClick
};

// Summary:
//
//
class Clickable : public GameObject
{
private:
    std::function<void(std::shared_ptr<sf::Sprite>, Game* game)> m_onHover;
    std::function<void(std::shared_ptr<sf::Sprite>, Game* game)> m_onUnHover;
    std::function<void(std::shared_ptr<sf::Sprite>, Game* game)> m_onClick;

protected:
    ButtonState m_bstate;

    void on_hover(Game* game);
    void on_click(Game* game);
    void on_unhover(Game* game);

public:
    Clickable(
        const std::string& id,
        std::shared_ptr<sf::Sprite> sprite,
        sf::IntRect& location,
        void(*onHover)(std::shared_ptr<sf::Sprite>, Game* game),
        void(*onUnHover)(std::shared_ptr<sf::Sprite>, Game* game),
        void(*onClick)(std::shared_ptr<sf::Sprite>, Game* game));

    virtual void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game);

    virtual void Draw(std::shared_ptr<sf::RenderWindow> window);
};

#endif // CLICKABLE_H