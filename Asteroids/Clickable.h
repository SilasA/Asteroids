#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>
#include <functional>

#include "GameObject.h"
#include "Game.h"

enum class ButtonState 
{
	kIdle,
	kHover,
	kClick
};

// Summary:
//
//
class Clickable : public GameObject
{
private:
	std::function<void(sf::Sprite*, Game*)> m_onHover;
	std::function<void(sf::Sprite*, Game*)> m_onUnHover;
	std::function<void(sf::Sprite*, Game*)> m_onClick;

protected:

	ButtonState m_bstate;

	void on_hover(Game* game);
	void on_click(Game* game);
	void on_unhover(Game* game);

public:
	Clickable(
		sf::Sprite& sprite,
		sf::IntRect& location,
		std::function<void(sf::Sprite*, Game*)> onHover,
		std::function<void(sf::Sprite*, Game*)> onUnHover,
		std::function<void(sf::Sprite*, Game*)> onClick);

	virtual void Update(sf::Window& window, sf::Event& event);

	virtual void Draw(sf::RenderWindow& window);
};

#endif // CLICKABLE_H