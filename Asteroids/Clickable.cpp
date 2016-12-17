#include "Clickable.h"
#include "Controls.h"
#include "GameMenuState.h"

Clickable::Clickable(
	sf::Sprite& sprite,
	sf::IntRect& location,
	std::function<void(sf::Sprite*, Game*)> onHover,
	std::function<void(sf::Sprite*, Game*)> onUnHover,
	std::function<void(sf::Sprite*, Game*)> onClick) :
	GameObject(sprite, location),
	// Members
	m_onHover(onHover),
	m_onUnHover(onUnHover),
	m_onClick(onClick)
{
	m_bstate = ButtonState::kIdle;
	m_sprite.setPosition(GameObject::RectToVec<float>(m_location));
}

void Clickable::Update(sf::Window& window, sf::Event& event)
{
	sf::Vector2i mpos = sf::Mouse::getPosition(window);
	if (m_location.contains(mpos))
	{
		if (MousePressed(event, sf::Mouse::Left))
		{
			m_bstate = ButtonState::kClick;
			on_click();
		}
		else
		{
			m_bstate = ButtonState::kHover;
			on_hover();
		}
	}
	else
	{
		m_bstate = ButtonState::kIdle;
		on_unhover();
	}
}

void Clickable::Draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Clickable::on_hover(Game* game)
{
	m_onHover(&m_sprite, game);
}

void Clickable::on_unhover(Game* game)
{
	m_onUnHover(&m_sprite, game);
}

void Clickable::on_click(Game* game)
{
	m_onClick(&m_sprite, game);
}