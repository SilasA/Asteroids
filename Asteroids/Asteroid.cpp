#include "Asteroid.h"

bool Asteroid::InCircle(float x, float y)
{
    float cX = m_sprite->getPosition().x + m_sprite->getTextureRect().width / 2;
    float cY = m_sprite->getPosition().y + m_sprite->getTextureRect().height / 2;
    return std::sqrtf(std::powf(x - cX, 2) + std::powf(y - cY, 2)) <= (m_sprite->getTextureRect().width / 2);
}

Asteroid::Asteroid(std::string& id, std::shared_ptr<sf::Sprite> sprite, sf::IntRect location) :
    GameObject(id, sprite, location), m_rotation(0)
{
    m_location = sf::IntRect{ m_location.left + m_location.width / 2, m_location.top + m_location.height / 2, m_location.width, m_location.height };
    m_sprite->setOrigin(sf::Vector2f{ (float)m_sprite->getTextureRect().width / 2, (float)m_sprite->getTextureRect().height / 2 });
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    if (m_sprite->getPosition().y >= window->getSize().y)
    {
        SetShot(true);
        return;
    }
    m_rotation += 1;
    m_sprite->setRotation(m_rotation);
    m_sprite->setPosition(m_location.left, m_sprite->getPosition().y + SPEED);
}

void Asteroid::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*m_sprite);
}