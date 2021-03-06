#include "GameObject.h"
#include "Utilities\Logger.h"
#include "Resources.h"

GameObject::GameObject(const std::string& id, std::shared_ptr<sf::Sprite> sprite, sf::IntRect& location) :
    Object(id),
    m_sprite(sprite), m_location(location)
{
    m_log->WriteLog(LogType::kInfo, Id(), "Initialized", "log");
}

bool GameObject::AddLabel(const std::string& label)
{
    if (!Resources::GetInstance()->font.loadFromFile(Resources::GetInstance()->textDir + "comic.ttf"))
    {
        m_log->WriteLog(LogType::kWarning, Id(), "Unable to load file comic.ttf");
        return false;
    }
    m_label = std::make_unique<Label>(this, label, Resources::GetInstance()->font);
    return true;
}

void GameObject::DrawLabel(std::shared_ptr<sf::RenderWindow> window)
{
    if (m_label.get() != nullptr)
        m_label->Draw(window);
}
void GameObject::UpdateLabel()
{
    if (m_label.get() != nullptr)
        m_label->Update();
}