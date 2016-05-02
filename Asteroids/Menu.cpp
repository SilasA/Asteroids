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

#include "stdafx.h"
#include "Menu.h"


_M Menu()
{
	buttons->push_back(Button{ 250, 75, "\\assets\\btn_play.png" });
	buttons->push_back(Button{ 250, 75, "\\assets\\btn_options.png" });
	buttons->push_back(Button{ 250, 75, "\\assets\\btn_exit.png" });
}


template<class T>
void _M run(sf::RenderWindow* window, T* mode)
{
	// Draw
	window->clear();
	window->draw(bg);
	for (auto button : *buttons)
		window->draw(button.getSprite());
	window->display();

	for (auto button : *buttons)
	{
		if (onButton(button))
			button.hover();
		if (onButton(button) && sf::Mouse::isButtonPressed(
			sf::Mouse::Button::Left))
			button.select();
	}

	for (auto button : *buttons)
	{
		if (button.type == ButtonType::PLAY && button.isSelected())
			mode = (T)4;
		if (button.type == ButtonType::OPTIONS && button.isSelected())
			mode = (T)2;
		if (button.type == ButtonType::EXIT && button.isSelected())
			mode = (T)6;
	}
}


bool _M onButton(Button& btn)
{
	return (sf::Mouse::getPosition().x > btn.getLeft() &&
			sf::Mouse::getPosition().x < btn.getRight() &&
			sf::Mouse::getPosition().y > btn.getTop() &&
			sf::Mouse::getPosition().y < btn.getBottom());
}