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
#include "SplashScreen.h"


_SS SplashScreen(sf::Time duration)
{
	_PROGRAM_DIR(_dir);

	this->duration = duration;
	remainingTime = duration;
	/*
	if (!tex.loadFromFile(std::string(_dir) + "\\assets\\splashscreen.png"))
		Logger::writeLog(1, "Splash", "unable to load texture");
	else
		Logger::writeLog(2, "Splash", "loaded texture");
		*/
	tex.setSmooth(true);
	splash.setTexture(tex);
	splash.setColor(sf::Color{ 0, 0, 0, 0 });
}


void _SS playSplash(sf::RenderWindow* window)
{
	float time_2 = duration.asMilliseconds() / 2;
	float targetFrameTime = time_2 / 10;

	window->clear(sf::Color::Black);
	
	timer.restart();
	tTimer.restart();

	while (isTime)
	{
		isTime = tTimer.getElapsedTime() >= duration;
		window->draw(splash);

		sf::Time tTimeTaken = (sf::seconds(targetFrameTime) -
			timer.getElapsedTime()) + timer.getElapsedTime();
		sf::sleep(sf::seconds(targetFrameTime) - tTimeTaken);
	}
	return;
}