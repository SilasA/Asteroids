#include "Indicator.h"

Indicator::Indicator(const std::string& id, sf::IntRect location, double min, double max, sf::Color color) :
    GUIObject(id)
{
    m_location = location;
    m_min = min;
    m_max = max;
    m_maxWidth = m_location.width;

    Set(m_max);

    m_bar = std::make_unique<sf::RectangleShape>(sf::Vector2f{ (float)m_location.width, (float)m_location.height });
    m_bar->setPosition(GameObject::RectToVec<float>(m_location));
    m_bar->setFillColor(color);
}

Indicator::~Indicator()
{
}

void Indicator::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    m_bar->setSize(sf::Vector2f{ (float)(m_value / m_max) * (float)m_maxWidth, m_bar->getSize().y });
}

void Indicator::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*m_bar.get());
}

double Indicator::Get()
{
    return m_value;
}

void Indicator::Set(double value)
{
    if (value <= m_max && value >= m_min)
        m_value = value;
}

void Indicator::SetProportion(double value)
{
    Set(value * m_max);
}
