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

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML\Graphics.hpp>
#include "Utilities.h
#include "Logger.h"

#define _B Button::

// \brief State of the menu bsuttons
// 
// IDLE		There is no mouse on/over the button
// HOVER	There is a mouse cursor over the button
// SELECTED The button has been selected
enum class ButtonState {
	IDLE,
	HOVER,
	SELECTED, };

//
//
//
enum class ButtonType {
	PLAY,
	OPTIONS,
	EXIT };


// \brief
//
//
//
class Button
{
private:

	sf::Texture tex;
	sf::Sprite btn;


	int btnWidth;
	int btnHeight;

	// Button frames
	sf::IntRect btnIdle;
	sf::IntRect btnHover;
	sf::IntRect btnSelected;

	ButtonState state;
	ButtonType type;

public:

	// \brief
	int doAction();

	///////////////////////////////////////////////////////////////////////////
	// GETTERS & SETTERS
	///////////////////////////////////////////////////////////////////////////

	// \return The respective location of the button
	float getLeft()	  { return btn.getPosition().x; }
	float getRight()  { return btn.getPosition().x + btnWidth; }
	float getTop()    { return btn.getPosition().y; }
	float getBottom() { return btn.getPosition().y + btnHeight; }

	// \return Whether or not the button is in the respective state
	bool isIdle()	  { return state == ButtonState::IDLE; }
	bool isHover()	  { return state == ButtonState::HOVER; }
	bool isSelected() { return state == ButtonState::SELECTED; }

	// \brief Set the state of the button to SELECTED
	void select() { state = ButtonState::SELECTED; }
	void hover() { state = ButtonState::HOVER; }
	void idle() { state = ButtonState::IDLE; }

	sf::Sprite getSprite() { return btn; }

	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR
	///////////////////////////////////////////////////////////////////////////

	Button(unsigned int width, unsigned int height, const std::string& dir);

};


#endif // BUTTON_H
