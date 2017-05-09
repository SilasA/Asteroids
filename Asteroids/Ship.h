#ifndef SHIP_H
#define SHIP_H

#include "GameObject.h"
#include "KeyBinds.h"

#include <memory>

// Summary:
//
//
class Ship : public GameObject
{
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

    std::shared_ptr<KeyBinds> m_keys;

public:
    Ship(std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location);
    ~Ship();

    void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;
};

#endif // SHIP_H