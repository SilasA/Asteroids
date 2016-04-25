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

#ifndef PROGRAMMAIN_H
#define PROGRAMMAIN_H

#include "Headers.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <time.h>

#define _PM ProgramMain::

// \brief The modes the application can go into
enum class Mode { 
	STARTUP,
	MENU,
	OPTIONS,
	CREDITS,
	ARCADE,
	FREEPLAY,
	CLOSE };

//
//
//
//
class ProgramMain : public ConfigHandler, public GameSave
{
private:

	Mode mode = Mode::STARTUP;

	// The window the entire program is run through
	sf::RenderWindow window{ { winWidth, winHeight },
		"Asteroids!" };

	GUI gui;

	Game game;

public:

	//
	void pgmMain();

	//
	ProgramMain();
};

#endif // PROGRAMMAIN_H