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
#include "GUI.h"

_GUI GUI()
{
	_PROGRAM_DIR(_dir);

	// Initialize UI text objects
	sf::Font* templateFont = new sf::Font();

	if (!templateFont->loadFromFile(std::string(_dir) +
		"\\assets\\ARCADECLASSIC.ttf"))
		Logger::writeLog(1, "GUI", "unable to load font");
	else
		Logger::writeLog(2, "GUI", "loaded font");

	for (int i = 0; i < _UI_ITEM_COUNT; i++)
		UIInfo[i] = sf::Text{ "999", *templateFont };

	// Set the text to the appropriate location
	//
	UIInfo[0].setPosition(sf::Vector2f{ 0, 0 });

	delete templateFont;

	// Slider indicators
	UISliders[0] = Slider{ 100, 0, 200, 25, sf::Vector2f{ 400, 300 } };

	// Initialize UI overlay
	if (!tex.loadFromFile(std::string(_dir) + "\\assets\\UI.png"))
		Logger::writeLog(1, "GUI", "unable to load texture");
	else
		Logger::writeLog(2, "GUI", "loaded texture");

	overlay.setTexture(tex);

}