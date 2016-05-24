///////////////////////////////////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
///				mixed with an equally popular game Galaga.
/// version 0.0.1
/// author: Silas Agnew <agnewsilas@gmail.com>
///
/// Created for a Showcase Project for CACC Programming and Mobile Applications
/// class with SFML - Simple and Fast Multimedia Library
/// 
/// This software can be used freely as open-source software with proper
/// representation of the author and following SFML's terms of use.
///
/// Improper representation may result in the following
/// 
///	- Disembowelment / forced Seppuku
///	- Smashing of the culprit's knees, ankles, or other vital joints
///	- Severing of the culprit's limb(s)
///	- RKO
/// - 360 no-scope(s)
///
/// Beware: These punishments will be enforced 95% of the time 35% of the time
///
///////////////////////////////////////////////////////////////////////////////


#ifndef CONTROLS_H
#define CONTROLS_H

//////////////////////////////////////////////////////////////////////////////
// GLOBAL
//////////////////////////////////////////////////////////////////////////////
#define _ESC sf::Keyboard::Escape

// Press/Release handlers
#define _MousePressed(enum) (sf::Mouse::isButtonPressed(enum))
#define _KeyPressed(enum) (sf::Keyboard::isKeyPressed(enum))
#define _KEY_RELEASED (sf::Event::KeyReleased)
#define _MOUSE_RELEASED (sf::Event::MouseButtonReleased)

//////////////////////////////////////////////////////////////////////////////
// MENU
//////////////////////////////////////////////////////////////////////////////
#define _L_CLICK sf::Mouse::Left
#define _R_CLICK sf::Mouse::Right

///////////////////////////////////////////////////////////////////////////////
// IN-GAME
///////////////////////////////////////////////////////////////////////////////
#define _LEFT_KB sf::Keyboard::A
#define _LEFT_AR sf::Keyboard::Left

#define _RIGHT_KB sf::Keyboard::D
#define _RIGHT_AR sf::Keyboard::Right

#define _UP_KB sf::Keyboard::W
#define _UP_AR sf::Keyboard::Up

#define _DOWN_KB sf::Keyboard::S
#define _DOWN_AR sf::Keyboard::Down

#define _SPACE sf::Keyboard::Space

///////////////////////////////////////////////////////////////////////////////
// GLOBAL CONSTANTS
///////////////////////////////////////////////////////////////////////////////

#define _WIN_WIDTH 800
#define _WIN_HEIGHT 600

#define _MAX_SHOT_DIS 10



#endif // CONTROLS_H


