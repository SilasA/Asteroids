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

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <vector>

#define _ANIM Animation::

// \brief The state of animated objects.
//
//	CREATING:	The animation is being created
//  CREATED:	The animation is created but not running
//	NORMAL:		The animation is looping normally  
//	PAUSED:		The animaiton loop is paused
//  EXPLODING:	The object is in the explosion animation
//	DESTROYED:	The object is destroyed
enum class State { CREATING, CREATED, NORMAL, PAUSED, EXPLODING, DESTROYED };


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

	// Time in between each frame.
	sf::Time frameTime;

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
	void loop(bool loop); 

	// Set the animation interval time
	void setFrameTime(sf::Time& time);
	void setFrameTime(unsigned int ms);

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

	// \brief Takes the initial variables for the animation to construct the 
	//		  Object.
	//	
	// \param frameArr	Array of the normal animation frames in sequence
	// \param frameArr2 Array of the explosion animation frames in sequence
	// \param loop		Whether or not to loop the animation or play it once
	// \param frameTime The time in between each frame.
	Animation(
		sf::IntRect* frameArr[], 
		sf::IntRect* frameArr2[], 
		bool loop, 
		sf::Time& frameTime);

	// \brief Takes the initial variables for the animation to construct the 
	//		  Object.
	//	
	// \param frameArr	Vector of the normal animation frames in sequence
	// \param frameArr2 Vector of the explosion animation frames in sequence
	// \param loop		Whether or not to loop the animation or play it once
	// \param frameTime The time in between each frame.
	Animation(
		std::vector<sf::IntRect>* frames1,
		std::vector<sf::IntRect>* frames2,
		bool loop,
		sf::Time& frameTime);

};

#endif /* ANIMATION_H */