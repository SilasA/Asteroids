/////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
/////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
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
/////////////////////////////////////////////////

#ifndef SOUND_H
#define SOUND_H

#include <SFML\Audio.hpp>

enum class State { STOPPED, PLAYING };


class Sound
{
private:

	// Temporary sound container before 
	sf::SoundBuffer tempSound;

	std::vector<sf::Sound> soundFX;
	
	State state;

public:

	// Adds a sound effect to the vector of sound effects.
	// Returns: Whether the sound was loaded or not.
	bool addSound(std::string& dir);

	// Returns the current state of the Sound FX.
	State getState() { return state; }

	Sound();


};


#endif /* SOUND_H */