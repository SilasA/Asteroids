#ifndef ASTEROID_MANAGER_H
#define ASTEROID_MANAGER_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "Object.h"
#include "Game.h"
#include "Asteroid.h"

// Summary:
//
class AsteroidManager : public Object
{
    friend class ShotManager;
private:
    float m_spawnTime;
    int m_maxVisible;
    int m_visible;
    int m_total;
    int m_spawned = 0;

    bool m_reachedTotal = false;
    bool m_isFinished = false;

    sf::Clock m_timer;

    sf::Texture m_asteroid;
    std::list<std::unique_ptr<Asteroid>> m_asteroids;

    std::string m_asteroidName = "Asteroid";
    int m_suffix = 0;

    void add_asteroid(sf::Vector2f startPos);
    void remove_asteroid(std::string& id);

public:
    AsteroidManager(const sf::Texture& tex, float spawnTime, int maxVisible, int total);
    ~AsteroidManager();

    void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game);
    void Draw(std::shared_ptr<sf::RenderWindow> window);

    void SetTotal(int total) { m_total = total; }
    int GetTotal() { return m_total; }

    void SetMaxVisible(int maxVisible) { m_maxVisible = maxVisible; }
    int GetMaxVisible() { return m_maxVisible; }

    bool IsFinished() { return m_asteroids.size() >= m_total; } // NOT right
};

#endif // ASTEROID_MANAGER_H