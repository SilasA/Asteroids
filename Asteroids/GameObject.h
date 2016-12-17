#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Object.h"

#include <SFML/Graphics.hpp>

// Summary:
//	Visual object within the game
//
class GameObject : public Object
{
protected:
	sf::IntRect m_location;

	sf::Sprite m_sprite;

public:
	GameObject(sf::Sprite& sprite, sf::IntRect& location);

	virtual void Update(sf::Window& window, sf::Event& event) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;

	// Extentions
	template<typename T, typename N>
	static sf::Vector2<T> RectToVec(sf::Rect<N>& rect)
	{
		return new sf::Vector2<T>((T)rect.left, (T)rect.top);
	}
};

#endif // GAME_OBJECT_H
