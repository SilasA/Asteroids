#ifndef SHIP_H
#define SHIP_H

#include "GameObject.h"

// Summary:
//
//
class Ship : public GameObject
{
private:
	int health;

	bool hasShield;
	bool hasSpeed;
	bool hasRapidFire;

public:
	Ship(sf::Sprite* sprite);
	~Ship();

	void Update(sf::Window& window, sf::Event& event, Game* game = nullptr) override;
	void Draw(sf::RenderWindow& window) override;
};

#endif // SHIP_H