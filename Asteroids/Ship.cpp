#include "Ship.h"
#include "ResourceHandler.h"

Ship::Ship(sf::Sprite* sprite) :
	GameObject("Ship", sprite, sf::IntRect{ 0, 0, 0, 0 })
{
}

Ship::~Ship()
{
	ResourceHandler::MakeUseless("ship");
}

void Ship::Update(sf::Window& window, sf::Event& event, Game* game)
{
}

void Ship::Draw(sf::RenderWindow& window)
{
}
