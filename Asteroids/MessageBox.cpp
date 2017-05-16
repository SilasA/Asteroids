#include "MessageBox.h"
#include "Resources.h"

const int MessageBox::VISIBLE_TIME = 9;
const float MessageBox::DEFAULT_H = 125;
const float MessageBox::DEFAULT_W = 250;

std::list<MessageBox> MessageBox::m_instances;

MessageBox::MessageBox(const std::string& id, const std::string& message, sf::IntRect location, int visibleTime) :
    GUIObject(id),
    m_main(sf::RectangleShape{ }),
    m_message(sf::Text{ message, Resources::GetInstance()->font })
{
    m_main.setFillColor(sf::Color{ 0x69, 0x69, 0x69, 0xff });
    m_main.setPosition(location.left, location.top);
    m_main.setSize(sf::Vector2f{ DEFAULT_W, DEFAULT_H });
    m_message.setPosition(location.left, location.top);
    m_timer.restart();
}

MessageBox::~MessageBox()
{
}

void MessageBox::UpdateAll(std::shared_ptr<sf::RenderWindow> window, sf::Event & event, Game * game)
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

void MessageBox::CreateMessage(const std::string& message, sf::IntRect location, int visibleTime)
{
    m_instances.emplace_back(MessageBox{ "random", message, location, visibleTime });
}
