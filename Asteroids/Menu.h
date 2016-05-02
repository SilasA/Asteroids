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

#ifndef MENU_H
#define MENU_H

#include <SFML\Graphics.hpp>
#include "Logger.h"
#include "Utilities.h"
#include "Button.h"

#define _M Menu::

// \brief 
//
//
//
class Menu
{
private:

	sf::Texture tex;
	sf::Sprite bg;

	int returnCode;

	bool onButton(Button& btn);

	std::vector<Button>* buttons;

	void pollForEvent();

	void doAction();

public:

	Menu();

	template<class T>
	void run(sf::RenderWindow* window, T* mode);




};

#endif MENU_H