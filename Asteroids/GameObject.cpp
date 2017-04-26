#include "GameObject.h"
#include "Utilities\Logger.h"

GameObject::GameObject(const std::string& id, std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location) :
    Object(id),
    m_sprite(sprite), m_location(location)
{
    m_log->WriteLog(LogType::kINFO, Id(), "Initialized", "log");
}