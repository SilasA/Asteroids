#include "GameObject.h"
#include "Utilities\Logger.h"
#include "Resources.h"

GameObject::GameObject(const std::string& id, std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location) :
    Object(id),
    m_sprite(sprite), m_location(location)
{
    m_log->WriteLog(LogType::kINFO, Id(), "Initialized", "log");
}

bool GameObject::AddLabel(const std::string& label)
{
    if (m_label == nullptr) return false;
    Resources::GetInstance()->font = std::make_shared<sf::Font>();
    if (!Resources::GetInstance()->font->loadFromFile(Resources::GetInstance()->textDir + "comic.ttf"))
        ;//log
    m_label = new Label(this, label, Resources::GetInstance()->font);
    return true;
}
