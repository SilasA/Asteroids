///////////////////////////////////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
///				mixed with an equally popular game Battlestar Galactica.
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

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <vector>

// The state of animated objects.
enum class State { CREATING, NORMAL, PAUSED, EXPLODING, DESTROYED };


///////////////////////////////////////////////////////////////////////////////
// \brief 
//
//
//
//
///////////////////////////////////////////////////////////////////////////////
class Animation
{
private:

	// Keeps track of time for animations.
	sf::Clock animTime;

	// Current index for the animations.
	int curAnimIndex = 0;

	// If the animation is to loop.
	bool isLoop = false;

	// Current state of object
	State state;

protected:

	// Normal animation
	std::vector<sf::IntRect> nFrames;

	// Explosion animation
	std::vector<sf::IntRect> eFrames;

	// Add a frame to the collection of frames.
	// PARAM ne: (n) represents normal frams; (e) represents explosion frames.
	// PARAM frame: location of the sprite in the texture.  
	// (left, top, width, height)
	void addFrame(char ne, sf::IntRect& frame);

	// Pause the animation.
	void pause();

	// Set whether the animation should loop or not.
	void loop(bool isloop); 

	// Set the animation interval time
	void setFrameTime(sf::Time& time);
	void setFrameTime(float ms);

	// 
	virtual void animate();

	// 
	virtual void explode();

	// Returns the index of the current frame the animation is on.
	int getCurIndex() { return curAnimIndex; }

	// Returns if the objects state is exploding
	bool isExploding() { return state == State::EXPLODING; }

	// Returns if the animation is paused.
	bool isPaused() { return state == State::PAUSED; }

	bool isLooping() { return isLoop; }

	// Default constructor
	Animation();

	// 
	Animation(sf::IntRect* frameArr[], sf::IntRect* frameArr2[], 
		bool loop, sf::Time& frameTime);
	Animation(std::vector<sf::IntRect>* frames1,
		std::vector<sf::IntRect>* frames2,
		bool loop, sf::Time& frameTime);

};

#endif /* ANIMATION_H */