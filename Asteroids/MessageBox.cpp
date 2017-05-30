#include "MessageBox.h"
#include "Resources.h"

const int MessageBox::VISIBLE_TIME = 9;
const float MessageBox::MAX_H = 200;
const float MessageBox::MAX_W = 300;
const float MessageBox::PADDING = 15;

std::list<MessageBox> MessageBox::m_instances;

MessageBox::MessageBox(const std::string& id, const std::string& message, sf::Vector2f location, int visibleTime) :
    GUIObject(id),
    m_main(sf::RectangleShape{ }),
    m_message(sf::Text{ message, Resources::GetInstance()->font }),
    m_visibleTimeSec(visibleTime)
{
    m_main.setFillColor(sf::Color{ 0x69, 0x69, 0x69, 0xff });
    m_main.setPosition(location.x, location.y);
    m_main.setSize(calculate_box_size(message));
    m_message.setPosition(location.x + PADDING, location.y + PADDING);
    m_timer.restart();
}

MessageBox::~MessageBox()
{
}

sf::Vector2f MessageBox::calculate_box_size(std::string message)
{
    while (m_message.getLocalBounds().width > MAX_W)
    {
        float p = m_message.findCharacterPos(0).x;
        for (int i = m_message.getString().getSize() - 1; i >= 0; i--)
        {
            if (m_message.findCharacterPos(i).x - p < MAX_W)
            {
                message = message.insert(i, "\n");
                m_message.setString(message);
                break;
            }
        }
    }
    return sf::Vector2f(m_message.getLocalBounds().width + PADDING * 2, m_message.getLocalBounds().height + PADDING * 2);
}

void MessageBox::UpdateAll(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    for (std::list<MessageBox>::iterator it = m_instances.begin(); it != m_instances.end();)
    {
        if (it->IsDone())
            it = m_instances.erase(it);
        else it++;
    }
}

void MessageBox::DrawAll(std::shared_ptr<sf::RenderWindow> window)
{
    for (std::list<MessageBox>::iterator it = m_instances.begin(); it != m_instances.end(); it++)
    {
        it->Draw(window);
    }
}

void MessageBox::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    // Nothing
}

void MessageBox::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(m_main);
    window->draw(m_message);
}

bool MessageBox::IsDone()
{
    return m_timer.getElapsedTime().asSeconds() >= sf::seconds(m_visibleTimeSec).asSeconds();
}

void MessageBox::CreateMessage(const std::string& message, sf::Vector2f location, int visibleTime)
{
    m_instances.emplace_back(MessageBox{ "random", message, location, visibleTime });
}