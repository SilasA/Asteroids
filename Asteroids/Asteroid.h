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
#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "GameObject.h"

// Summary:
//  Represents an asteroid for the player to shoot
class Asteroid : public GameObject
{
    friend class AsteroidManager;
private:
    const int SPEED = 3;

    float m_rotation;

    bool m_isShot = false;

    sf::Vector2f m_startPosition;

public:
    Asteroid(std::string& id, std::shared_ptr<sf::Sprite> sprite, sf::IntRect location);
    ~Asteroid();

    virtual void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) override;
    virtual void Draw(std::shared_ptr<sf::RenderWindow> window) override;

    bool IsShot() { return m_isShot; }
    void SetShot(bool shot) { m_isShot = shot; }

    bool InCircle(float x, float y);
};

#endif // ASTEROID_H