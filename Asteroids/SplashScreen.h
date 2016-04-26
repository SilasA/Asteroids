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

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML\Graphics.hpp>
#include "Utilities.h"
#include "Logger.h"

#define _SS SplashScreen::

// \brief 
//
//
//
class SplashScreen
{
private:

	sf::Texture tex;
	sf::Sprite splash;

	sf::Time duration;
	sf::Time remainingTime;
	sf::Clock timer;
	sf::Clock tTimer;

	bool isTime = true;

public:

	// \brief Constructs the Splash Screen
	// \param duration Total duration of the splash screen
	SplashScreen(sf::Time duration);

	// \brief Plays the splash screen to the defined time
	// \param window The window that the splash is to be displayed on
	void playSplash(sf::RenderWindow* window);

};


#endif // SPLASHSCREEN_H