#include "GameObject.h"

#include <Logger.h>

GameObject::GameObject(const std::string& id, sf::Sprite& sprite, sf::IntRect& location) :
	Object(id),
	m_sprite(sprite), m_location(location)
{
	Logger::WriteLog(LogType::kINFO, Id(), "Initialized", "log");
}
