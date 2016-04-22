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

#include <SFML\Graphics.hpp>
#include <iostream>

#include "Slider.h"

#define _GUI GUI::
#define _UI_ITEM_COUNT 10
#define _UI_SLIDER_COUNT 10

///////////////////////////////////////////////////////////////////////////////
// \brief
//
//
//
//
///////////////////////////////////////////////////////////////////////////////
class GUI
{
private:

	sf::Texture tex;
	sf::Sprite overlay;

	// \brief Array of the UI text form indicators
	//
	// 0: Score
	// 1: Difficulty
	// 2:
	// 3:
	// 4:
	sf::Text UIInfo[_UI_ITEM_COUNT];

	// \brief Array of the UI Slider indicators
	//
	// 0:
	// 1:
	// 2:
	// 3:
	Slider UISliders[_UI_SLIDER_COUNT];

public:

	GUI();
};