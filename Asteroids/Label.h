#ifndef LABEL_H
#define LABEL_H

#include <SFML\Graphics.hpp>
#include <memory>

class GameObject;

// Summary:
// 
class Label
{
private:
    GameObject* m_parent;

    sf::Text m_text;

public:
    Label(GameObject* parent, const std::string& text, sf::Font& font);
    ~Label();

    void Update();
    void Draw(std::shared_ptr<sf::RenderWindow> window);
};

#endif // LABEL_H