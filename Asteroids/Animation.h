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

#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <SFML\Graphics.hpp>
#include <vector>

#include "Utilities.h"

///////////////////////////////////////////////////////////////////////////////
// \brief A preset of frame indices that create an animation sequence
///////////////////////////////////////////////////////////////////////////////
class Animation
{
public:

	uint startFrame;
	uint endFrame;
	uint frameTime;

	int getLength() { return endFrame - startFrame + 1; }

	Animation(uint start, uint end, uint time)
	{
		startFrame = start;
		endFrame = end;
		frameTime = time;
	}
};


///////////////////////////////////////////////////////////////////////////////
// \brief 
//
//
//
//
///////////////////////////////////////////////////////////////////////////////
class AnimationHandler
{
private:

	std::vector<Animation> animations;

	float time;

	int currentAnim;

public:

	// Current frame's sprite location in texture
	sf::IntRect curBounds;

	void update();

	void addAnim(Animation& anim);

	void changeAnim(uint index);

	AnimationHandler();

};

#endif /* ANIMATIONHANDLER_H */