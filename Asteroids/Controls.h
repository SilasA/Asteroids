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
#ifndef CONTROLS_H
#define CONTROLS_H

//////////////////////////////////////////////////////////////////////////////
// GLOBAL
//////////////////////////////////////////////////////////////////////////////
#define ESC sf::Keyboard::Escape

//////////////////////////////////////////////////////////////////////////////
// MENU
//////////////////////////////////////////////////////////////////////////////
#define L_CLICK sf::Mouse::Left
#define R_CLICK sf::Mouse::Right

///////////////////////////////////////////////////////////////////////////////
// IN-GAME
///////////////////////////////////////////////////////////////////////////////
#define KB_LEFT sf::Keyboard::A
#define AK_LEFT sf::Keyboard::Left

#define KB_RIGHT sf::Keyboard::D
#define AK_RIGHT sf::Keyboard::Right

#define KB_UP sf::Keyboard::W
#define AK_UP sf::Keyboard::Up

#define KB_DOWN sf::Keyboard::S
#define AK_DOWN sf::Keyboard::Down

#define SPACE sf::Keyboard::Space

///////////////////////////////////////////////////////////////////////////////
// INPUT
///////////////////////////////////////////////////////////////////////////////

#define KEY_RELEASED (sf::Event::KeyReleased)
#define MOUSE_RELEASED (sf::Event::MouseButtonReleased)

// Press/Release handlers
static bool MousePressed(sf::Event& event, sf::Mouse::Button&& button)
{
    return event.mouseButton.button == button;
}

static bool KeyPressed(sf::Event& event, sf::Keyboard::Key&& key)
{
    return event.key.code == key;
}

#endif // CONTROLS_H
