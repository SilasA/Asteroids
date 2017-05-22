#include "ShotManager.h"

ShotManager::ShotManager() :
    Object("Shot Manager")
{
}

ShotManager::~ShotManager()
{
}

void ShotManager::Update(std::shared_ptr<AsteroidManager> asteroidMgr, std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    bool erased = false;
    for (std::list<sf::RectangleShape>::iterator it = m_lasers.begin(); it != m_lasers.end();)
    {
        for (std::unique_ptr<Asteroid>& a : asteroidMgr->m_asteroids)
        {
            erased = false;
            if (a->InCircle(it->getPosition().x, it->getPosition().y))
            {
                a->SetShot(true);
                it = m_lasers.erase(it);
                erased = true;
                break;
            }
        }
        if (!erased)
        {
            it->setPosition(sf::Vector2f{ it->getPosition().x, it->getPosition().y - LASER_SPEED });
            it++;
        }
    }
}

void ShotManager::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    for (sf::RectangleShape& s : m_lasers)
        window->draw(s);
}

void ShotManager::Shoot(GameObject* ship)
{
    m_lasers.push_back(sf::RectangleShape(sf::Vector2f{ (float)LASER_W, (float)LASER_H }));
    m_lasers.back().setPosition(sf::Vector2f{
        ship->GetSprite()->getPosition().x + ship->GetSprite()->getTextureRect().width / 2,
        ship->GetSprite()->getPosition().y });
    m_lasers.back().setFillColor(sf::Color::Red);
}