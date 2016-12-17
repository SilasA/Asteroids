///////////////////////////////////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
//				mixed with an equally popular game Galaga.
// version 0.0.1
// author: Silas Agnew <agnewsilas@gmail.com>
//
// Created for a Showcase Project for CACC Programming and Mobile Applications
// class with SFML - Simple and Fast Multimedia Library
// 
// This software can be used freely as open-source software with proper
// representation of the author and following SFML's terms of use.
//
// Improper representation may result in the following
// 
//	- Disembowelment / forced Seppuku
//	- Smashing of the culprit's knees, ankles, or other vital joints
//	- Severing of the culprit's limb(s)
//	- RKO
//  - 360 no-scope(s)
//
// Beware: These punishments will be enforced 95% of the time 35% of the time
//
///////////////////////////////////////////////////////////////////////////////

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>

#include "Object.h"


enum class AnimationState {
	kCreating,
	kNormal,
	kExploding,
	kExploded,
};


// Summary:
//
//
class AnimSequence
{
public:

	unsigned int m_startFrame;
	unsigned int m_endFrame;

	float m_duration;

	int GetLength() { return m_endFrame - m_startFrame + 1; }

	AnimSequence(unsigned int startFrame, unsigned int endFrame, float duration)
	{
		m_startFrame = startFrame;
		m_endFrame = endFrame;
		m_duration = duration;
	}
};


// Summary:
//
//
class Animation : public Object
{
private:

	std::vector<AnimSequence> m_sequences;

	float m_time;

	int m_curAnim;

	AnimationState m_animState;

public:

	sf::IntRect m_bound;
	sf::IntRect m_frameSize;

	AnimationState GetAnimState() { return m_animState; }

	void AddSequence(AnimSequence& seq);

	void ChangeSequence(unsigned int seq);


	Animation(const std::string& id);
	Animation(const std::string& id, sf::IntRect& frameSize);

	~Animation();
};

#endif // ANIMATION_H