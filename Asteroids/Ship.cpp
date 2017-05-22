#include "Ship.h"
#include "Resources.h"

Ship::Ship(std::shared_ptr<AsteroidManager> asteroidMgr, std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location) :
    GameObject("Ship", sprite)
{
    m_initPosition = location;
    sprite->setPosition(GameObject::RectToVec<float, int>(location));
    sprite->setColor(sf::Color::White);
    m_sprite->setTextureRect(sf::IntRect{ 0, 0, (int)m_sprite->getTexture()->getSize().x / 2, (int)m_sprite->getTexture()->getSize().y / 2 });
    m_keys = KeyBinds::GetInstance();
    m_asteroidMgr = asteroidMgr;
    m_shotMgr = std::make_unique<ShotManager>();
    m_shotTimer.restart();
}

Ship::~Ship()
{
}

void Ship::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    sf::IntRect rect = m_sprite->getTextureRect();

    m_isFiring = sf::Keyboard::isKeyPressed(m_keys->GetKey("Shoot"));

    if (m_isFiring && m_shotTimer.getElapsedTime().asSeconds() >= .75)
    {
        m_shotMgr->Shoot(this);
        m_shotTimer.restart();
    }

    // Y
    if (sf::Keyboard::isKeyPressed(m_keys->GetKey("Up")))
    {
        m_velocity.y = -7;
        m_isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(m_keys->GetKey("Down")))
    {
        m_velocity.y = 7;
        m_isMoving = true;
    }
    else
    {
        m_velocity.y = 0;
    }

    // X
    if (sf::Keyboard::isKeyPressed(m_keys->GetKey("Left")))
    {
        m_velocity.x = -10;
        m_isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(m_keys->GetKey("Right")))
    {
        m_velocity.x = 10;
        m_isMoving = true;
    }
    else
    {
        m_velocity.x = 0;
    }

    m_isMoving = !!m_velocity.x || !!m_velocity.y;

    if (m_isFiring)
        rect = sf::IntRect{ rect.left, (int)m_sprite->getTexture()->getSize().y / 2, rect.width, rect.height };
    else
        rect = sf::IntRect{ rect.left, 0, rect.width, rect.height };

    if (m_isMoving)
        rect = sf::IntRect{ (int)m_sprite->getTexture()->getSize().x / 2, rect.top, rect.width, rect.height };
    else
        rect = sf::IntRect{ 0, rect.top, rect.width, rect.height };

    m_sprite->setTextureRect(rect);

    // Bounds
    sf::Vector2f pos = m_sprite->getPosition() + m_velocity;
    if (pos.x > window->getSize().x - m_sprite->getTextureRect().width)
        pos.x = window->getSize().x - m_sprite->getTextureRect().width;
    else if (pos.x < 0)
        pos.x = 0;
    if (pos.y > window->getSize().y - m_sprite->getTextureRect().height)
        pos.y = window->getSize().y - m_sprite->getTextureRect().height;
    else if (pos.y < window->getSize().y - 300)
        pos.y = window->getSize().y - 300;

    m_sprite->setPosition(pos);
    m_shotMgr->Update(m_asteroidMgr, window, event, game);
}

void Ship::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*m_sprite);
    m_shotMgr->Draw(window);
}