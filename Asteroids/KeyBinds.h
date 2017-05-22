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
#ifndef KEY_BINDS_H
#define KEY_BINDS_H

#include "Persistance.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

// Summary:
//  Stores, Loads, and Saves key bindings
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