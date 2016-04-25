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
#include "ProgramMain.h"


_PM ProgramMain()
{
	// Find data
	findSaves();

	//setConfig();
}


void _PM pgmMain()
{
	window.setFramerateLimit(frameRate);

	switch (mode)
	{
	case Mode::STARTUP:
		break;
	case Mode::MENU:
		// Menu window control
		break;
	case Mode::OPTIONS:
		// Option window control
		break;
	case Mode::CREDITS:
		// Credit window control
		break;
	case Mode::ARCADE:
		// Arcade mode window control
		break;
	case Mode::FREEPLAY:
		// Freeplay mode window control
		break;
	case Mode::CLOSE:
		// Close window control
		break;
	default:
		break;
	}

}