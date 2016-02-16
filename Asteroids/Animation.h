//

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <vector>

// The state of animated objects.
enum class State { CREATING, NORMAL, EXPLODING, EXPLODED };


class Animation
{
private:

	// Keeps track of time for animations.
	sf::Clock animTime;

	// Current index for the animations.
	int curAnimIndex = 0;

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

	// 
	virtual void animate();

	// 
	virtual void explode();

	// Returns the index of the current frame the animation is on.
	int getCurIndex() { return curAnimIndex; }

	// Returns if the objects state is exploding
	bool isExploding() { return state == State::EXPLODING; }

	// 
	Animation();
};

#endif /* ANIMATION_H */