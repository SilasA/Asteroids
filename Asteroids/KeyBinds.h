#ifndef KEY_BINDS_H
#define KEY_BINDS_H

#include "Persistance.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

// Summary:
//
class KeyBinds
{
private:
    const std::string TAG = "keys";

    std::map<std::string, sf::Keyboard::Key> m_keyMap;

public:
    KeyBinds();
    ~KeyBinds();

    static std::shared_ptr<KeyBinds> GetInstance();

    bool SaveState(std::shared_ptr<Persistance> persistance);
    bool LoadState(std::shared_ptr<Persistance> persistance);

    sf::Keyboard::Key GetKey(const std::string& name);
    void SetKey(const std::string& name, sf::Keyboard::Key key);
};

inline bool MousePressed(sf::Event& event, sf::Mouse::Button&& button)
{
    return event.mouseButton.button == button;
}

inline bool KeyPressed(sf::Event& event, sf::Keyboard::Key&& key)
{
    return event.key.code == key;
}

#endif // KEY_BINDS_H