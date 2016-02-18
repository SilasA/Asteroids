//

#ifndef SOUND_H
#define SOUND_H

#include <SFML\Audio.hpp>
#include "Log.h"

enum class State { STOPPED, PLAYING };


class Sound : public Log
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