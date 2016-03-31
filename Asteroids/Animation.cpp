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
#include "Animation.h"

#include <SFML\Graphics.hpp>
#include <vector>


_ANIM Animation()
{
	state = State::CREATING;
}

_ANIM Animation(
	sf::IntRect* frameArr[],
	sf::IntRect* frameArr2[],
	bool loop,
	sf::Time& frameTime)
{
	state = State::CREATING;

	// Transfer array contents to the appropriate vector
	for (int i = 0; i < _ARRAY_SIZE(frameArr); i++)
		nFrames.push_back(*frameArr[i]);
	for (int j = 0; j < _ARRAY_SIZE(frameArr2); j++)
		eFrames.push_back(*frameArr2[j]);

	// Set if animation loops or not
	isLoop = loop;

	// Set time in between frames
	setFrameTime(frameTime);

	state = State::CREATED;
}


_ANIM Animation(
	std::vector<sf::IntRect>* frames1,
	std::vector<sf::IntRect>* frames2,
	bool loop,
	sf::Time& frameTime)
{
	state = State::CREATING;

	// Set frame vectors
	nFrames = *frames1;
	eFrames = *frames2;

	// Set if animation loops or not
	isLoop = loop;

	// Set time in between frames
	setFrameTime(frameTime);

	state = State::CREATED;
}


void _ANIM addFrame(char ne, sf::IntRect& frame)
{
	if (ne == 'n') // Normal frames
		nFrames.push_back(frame);
	else if (ne == 'e') // Explosion frames
		eFrames.push_back(frame);
}


void _ANIM pause()
{
	state = State::PAUSED;
}


void _ANIM loop(bool loop)
{
	isLoop = loop;
}


void _ANIM setFrameTime(sf::Time& time)
{
	frameTime = time;
}


void _ANIM setFrameTime(float ms)
{
	frameTime = sf::milliseconds(ms);
}


void _ANIM animate()
{

}


void _ANIM explode()
{

}