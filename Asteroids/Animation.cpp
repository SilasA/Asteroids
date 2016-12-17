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
#include <Logger.h>

#include "Animation.h"


std::string sequence_stos(AnimationState state);


void Animation::AddSequence(AnimSequence& seq)
{
	m_sequences.push_back(seq);
}


void Animation::ChangeSequence(unsigned int seq)
{
	m_curAnim = seq;
	Logger::WriteLog(LogType::kINFO,
		Id(),
		"animation sequence changed: " + sequence_stos((AnimationState)seq),
		"log");
}


void Animation::Update(float dt)
{
}


Animation::Animation(const std::string& id) :
	Object(id)
{
	m_time = 0.f;
	m_curAnim = -1;
}


Animation::Animation(const std::string& id, sf::IntRect& frameSize) :
	Object(id),
	m_frameSize(frameSize)
{
	m_time = 0.f;
	m_curAnim = -1;
}


Animation::~Animation()
{
}


std::string sequence_stos(AnimationState state)
{
	switch (state)
	{
	case AnimationState::kCreating:
		return "{Creating}";
		break;
	case AnimationState::kNormal:
		return "{Normal}";
		break;
	case AnimationState::kExploding:
		return "{Exploding}";
		break;
	case AnimationState::kExploded:
		return "{Exploded}";
		break;
	default:
		break;
	}
	return "";
}