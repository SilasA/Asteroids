#include "Asteroid.h"

Asteroid::Asteroid(std::shared_ptr<sf::Sprite> sprite, sf::IntRect location) :
    GameObject("Asteroids", sprite, location), m_rotation(0)
{
    m_location = sf::IntRect{ m_location.left + m_location.width / 2, m_location.top + m_location.height / 2, m_location.width, m_location.height };
    m_sprite->setOrigin(sf::Vector2f{ (float)m_sprite->getTextureRect().width / 2, (float)m_sprite->getTextureRect().height / 2 });
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    m_rotation += 1;
    m_sprite->setRotation(m_rotation);
    m_sprite->setPosition(m_location.left, m_location.top);
}

void Asteroid::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*m_sprite);
}