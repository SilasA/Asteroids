#include "Label.h"
#include "GameObject.h"

Label::Label(GameObject* parent, const std::string& text, sf::Font& font) :
    m_parent(parent), m_text(text, font)
{
}

Label::~Label()
{
}

void Label::Update()
{
    m_text.setPosition(
        m_parent->m_location.left + m_parent->m_location.width / 2 - m_text.getLocalBounds().width / 2,
        m_parent->m_location.top + m_parent->m_location.height / 2 - m_text.getLocalBounds().height / 2);
    m_text.setColor(sf::Color::Black);
}

void Label::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(m_text);
}