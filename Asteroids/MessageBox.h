///////////////////////////////////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
//				mixed with an equally popular game Galaga.
// version 0.0.1
// author: Silas Agnew <agnewsilas@gmail.com>
//
// Created for a Showcase Project for CACC Programming and Mobile Applications
// class with SFML - Simple and Fast Multimedia Library
//
// This software can be used freely as open-source software with proper
// representation of the author and following SFML's terms of use.
//
// Improper representation may result in the following
//
//	- Disembowelment / forced Seppuku
//	- Smashing of the culprit's knees, ankles, or other vital joints
//	- Severing of the culprit's limb(s)
//	- RKO
//  - 360 no-scope(s)
//
// Beware: These punishments will be enforced 95% of the time 35% of the time
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MESSAGE_BOX_H
#define MESSAGE_BOX_H

#include <list>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <memory>

#include "GUIObject.h"

// Summary:
//
class MessageBox : public GUIObject
{
private:
    sf::RectangleShape m_main;
    sf::Text m_message;

    sf::Clock m_timer;
    int m_visibleTimeSec;

    static std::list<MessageBox> m_instances;

    sf::Vector2f calculate_box_size(std::string message);

public:
    const static int VISIBLE_TIME;
    const static float MAX_H;
    const static float MAX_W;
    const static float PADDING;

    MessageBox(const std::string& id, const std::string& message, sf::Vector2f location, int visibleTime);
    ~MessageBox();

    static void UpdateAll(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game);
    static void DrawAll(std::shared_ptr<sf::RenderWindow> window);

    void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;

    bool IsDone();

    static void CreateMessage(const std::string& message, sf::Vector2f location, int visibleTime = VISIBLE_TIME);
};

#endif // MESSAGE_BOX_H