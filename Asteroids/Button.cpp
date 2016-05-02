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
#include "Button.h"


_B Button(unsigned int width, unsigned int height, const std::string& dir)
{
	_PROGRAM_DIR(_dir);

	btnWidth = width;
	btnHeight = height;

	btnIdle = sf::IntRect{ 0, 0, (int)width, (int)height };
	btnHover = sf::IntRect{ 0, (int)height, (int)width, (int)height };
	btnSelected = sf::IntRect{ 0, (int)height * 2, (int)width, (int)height };

	if (!tex.loadFromFile(std::string(_dir) + dir))
		Logger::writeLog(1, "Button", "unable to load texture");
	else
		Logger::writeLog(2, "Button", "loaded texture");

	state = ButtonState::IDLE;
}


int _B doAction()
{
	switch (type)
	{
	case ButtonType::PLAY:
		return (int)ButtonType::PLAY;
		break;
	case ButtonType::OPTIONS:
		return (int)ButtonType::OPTIONS;
		break;
	case ButtonType::EXIT:
		return (int)ButtonType::EXIT;
		break;
	}
}

