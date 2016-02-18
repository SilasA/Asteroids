//

#include "Sound.h"


Sound::Sound()
{
	state = State::STOPPED;
}


bool Sound::addSound(std::string& dir)
{
	if (tempSound.loadFromFile(dir))
	{
		soundFX.push_back(sf::Sound{ tempSound });
		writeFileFoundLog(dir);
		return true;
	}
	return false;
}