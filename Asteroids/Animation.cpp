//

#include <SFML\Graphics.hpp>
#include <vector>

#include "Animation.h"


Animation::Animation()
{
	state = State::CREATING;
}


void Animation::addFrame(char ne, sf::IntRect& frame)
{
	if (ne == 'n') // Normal frames
		nFrames.push_back(frame);
	else if (ne == 'e') // Explosion frames
		eFrames.push_back(frame);
}


void Animation::animate()
{

}


void Animation::explode()
{

}