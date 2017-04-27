#include "Label.h"
#include "GameObject.h"

Label::Label(GameObject* parent, const std::string& text, std::shared_ptr<sf::Font> font) :
    m_parent(parent), m_text(text, *font.get())
{
}

Label::~Label()
{
}

void Label::Update()
{
    m_text.setPosition(m_parent->m_location.left, m_parent->m_location.top);
}

void Label::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(m_text);
}
