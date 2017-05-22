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
#ifndef SHIP_H
#define SHIP_H

#include "GameObject.h"
#include "KeyBinds.h"
#include "ShotManager.h"

#include <memory>

// Summary:
//
class Ship : public GameObject
{
    friend class ShotManager;
private:
    int m_health;

    bool m_hasShield = false;
    bool m_hasSpeed = false;
    bool m_hasRapidFire = false;

    // States
    bool m_isMoving = false;
    bool m_isFiring = false;

    sf::IntRect m_initPosition;

    sf::Vector2f m_velocity;

    sf::Clock m_shotTimer;

    std::shared_ptr<AsteroidManager> m_asteroidMgr;
    std::unique_ptr<ShotManager> m_shotMgr;

    std::shared_ptr<KeyBinds> m_keys;

public:
    Ship(std::shared_ptr<AsteroidManager> asteroidMgr, std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location);
    ~Ship();

    void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;
};

#endif // SHIP_H