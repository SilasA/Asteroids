#ifndef SHOT_MANAGER_H
#define SHOT_MANAGER_H

#include <SFML\Graphics.hpp>
#include <list>
#include <memory>

#include "Game.h"
#include "GameObject.h"
#include "Object.h"
#include "AsteroidManager.h"

// Summary:
//
class ShotManager : public Object
{
private:
    std::list<sf::RectangleShape> m_lasers;

    const int LASER_W = 5;
    const int LASER_H = 10;
    const int LASER_SPEED = 3;

public:
    ShotManager();
    ~ShotManager();

    void Update(std::shared_ptr<AsteroidManager> asteroidMgr, std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game);
    void Draw(std::shared_ptr<sf::RenderWindow> window);

    void Shoot(GameObject* ship);
};

#endif // SHOT_MANAGER_H