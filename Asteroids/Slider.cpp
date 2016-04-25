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
#include "Slider.h"


_SL Slider()
{
	_PROGRAM_DIR(_dir);

	if (!tex.loadFromFile(std::string(_dir) + "\\assets\\slider.png"))
		Logger::writeLog(1, "Slider", "unable to load image");
	slider.setTexture(tex);
}


_SL Slider(
	unsigned int maxVal,
	unsigned int minVal,
	unsigned int width,
	unsigned int height,
	sf::Vector2f pos)
{
	this->maxVal = maxVal;
	this->minVal = minVal;
	this->width = width;
	this->height = height;

	setValue(maxVal);

	// Create Texture/Sprite
	if (!tex.loadFromFile(std::string(_dir) + "\\assets\\slider.png",
		sf::IntRect(0, 0, width, height)))
		Logger::writeLog(1, "Slider", "unable to load image");

	slider.setTexture(tex);
	slider.setPosition(pos);
	//slider.setColor(sf::Color::Green);
	
	usable = true;
}


void _SL setSliderRange(unsigned int maxVal, unsigned int minVal)
{
	this->maxVal = maxVal;
	this->minVal = minVal;
}


void _SL setSliderDim(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;

	if (!usable)
	{
		slider.setTextureRect(sf::IntRect(0, 0, width, height));
		usable = true;
	}
}


bool _SL setValue(unsigned int value)
{
	if (value <= maxVal && value >= minVal)
		curVal = value;
	return curVal == value;
}


void _SL setSliderPos(sf::Vector2f pos)
{
	slider.setPosition(pos);
}


void _SL update()
{
	if (!usable) return;

	slider.setTextureRect(sf::IntRect(0, 0, 
		(curVal / maxVal) * width, height));
}