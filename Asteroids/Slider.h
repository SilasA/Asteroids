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
#include "Logger.h"

#define _SL Slider::

// \brief
//
//
//
//
class Slider
{
private:

	unsigned int maxVal = 1;
	unsigned int minVal = 0;
	unsigned int width;
	unsigned int height;
	unsigned int curVal;

	bool usable = false;

	sf::Texture tex;
	sf::Sprite slider;

public:
	
	//
	void update();


	///////////////////////////////////////////////////////////////////////////
	// GETTERS & SETTERS
	///////////////////////////////////////////////////////////////////////////

	// \brief Sets the slider's upper and lower range
	void setSliderRange(unsigned int maxVal, unsigned int minVal);

	// \brief Sets the slider's dimensions
	void setSliderDim(unsigned int width, unsigned int height);

	// \brief Sets the sliders value in between the range
	// \return If the set was successful
	bool setValue(unsigned int value);

	// \brief Sets the position of the slider
	void setSliderPos(sf::Vector2f pos);

	// \brief Sets the color of the slider
	void setColor(sf::Color& color);

	// \return Slider upper range
	int getSliderUpper() { return maxVal; }

	// \return Slider lower range
	int getSliderLower() { return minVal; }

	// \return Current value of the slider
	int getCurVal() { return curVal; }

	// \return Position of the slider
	sf::Vector2f getSliderPos() { return slider.getPosition(); }

	// \return Color of the slider
	sf::Color getSliderColor() { return slider.getColor(); }

	///////////////////////////////////////////////////////////////////////////
	// OPERATOR
	///////////////////////////////////////////////////////////////////////////

	// \brief Comparision operators compare the value of the slider
	bool operator==(Slider& right) { return curVal == right.curVal; }
	bool operator!=(Slider& right) { return curVal != right.curVal; }
	bool operator<=(Slider& right) { return curVal <= right.curVal; }
	bool operator>=(Slider& right) { return curVal >= right.curVal; }
	bool operator<(Slider& right)  { return curVal < right.curVal; }
	bool operator>(Slider& right)  { return curVal > right.curVal; }

	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	///////////////////////////////////////////////////////////////////////////

	// \brief Creates a slider indicator without setting any parameters
	Slider();

	// \brief Creates a slider indicator mainly for the UI overlay
	//
	// \param maxVal The maximum value the slider will extend to
	// \param minVal The minimum value the slider will extend to
	// \param width  The width of the slider in pixels
	// \param height The height of the slider in pixels
	// \param pos	 The position of the slider from the origin
	Slider(
		unsigned int maxVal,
		unsigned int minVal,
		unsigned int width,
		unsigned int height,
		sf::Vector2f pos);
};