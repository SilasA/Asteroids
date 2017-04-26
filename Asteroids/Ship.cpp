#include "Ship.h"
#include "Resources.h"

Ship::Ship(std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location) :
    GameObject("Ship", sprite)
{
    m_initPosition = location;
    sprite->setPosition(GameObject::RectToVec<float, int>(location));
}

Ship::~Ship()
{
}

void Ship::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    sf::IntRect rect = m_sprite->getTextureRect();
    if (m_isFiring)
        rect.top = m_sprite->getTexture()->getSize().y / 2;
    else
        rect.top = 0;

    if (m_isMoving)
        rect.left = m_sprite->getTexture()->getSize().x / 2;
    else
        rect.left = 0;
    m_sprite->setTextureRect(rect);
}

void Ship::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*m_sprite);
}