#ifndef GUI_OBJECT_H
#define GUI_OBJECT_H

#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Object.h"

// Summary:
//
class GUIObject : public Object
{
public:
    GUIObject(const std::string& id);
    ~GUIObject();

    virtual void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) = 0;

    virtual void Draw(std::shared_ptr<sf::RenderWindow> window) = 0;
};

#endif // GUI_OBJECT_H