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
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <memory>

#include "Object.h"
#include "Game.h" // May become a problem
#include "Label.h"

#include <SFML/Graphics.hpp>

// Summary:
//	Visual object within the game
class GameObject : public Object
{
    friend Label;
protected:
    sf::IntRect m_location;

    std::shared_ptr<sf::Sprite> m_sprite;

    std::unique_ptr<Label> m_label;

public:
    GameObject(const std::string& id, std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location = sf::IntRect{ 0, 0, 0, 0 });

    virtual void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) = 0;

    virtual void Draw(std::shared_ptr<sf::RenderWindow> window) = 0;

    virtual bool AddLabel(const std::string& label);
    void DrawLabel(std::shared_ptr<sf::RenderWindow> window);
    void UpdateLabel();

    std::shared_ptr<sf::Sprite> GetSprite() { return m_sprite; }

    // Extentions
    template<typename T, typename N>
    static sf::Vector2<T> RectToVec(sf::Rect<N>& rect)
    {
        return sf::Vector2<T>((T)rect.left, (T)rect.top);
    }
};

#endif // GAME_OBJECT_H
