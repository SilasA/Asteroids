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

    static std::list<MessageBox> m_instances;

public:
    const int VISIBLE_TIME = 9;
    const float DEFAULT_H = 125;
    const float DEFAULT_W = 250;

    MessageBox(const std::string& id, const std::string& message, sf::IntRect location);
    ~MessageBox();

    static void UpdateAll(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game);
    static void DrawAll(std::shared_ptr<sf::RenderWindow> window);

    void Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;

    bool IsDone();

    static void CreateMessage(const std::string& message, sf::IntRect location);
};

#endif // MESSAGE_BOX_H