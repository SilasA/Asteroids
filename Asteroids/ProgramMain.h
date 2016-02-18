//

#ifndef PROGRAMMAIN_H
#define PROGRAMMAIN_H

#include <SFML\Graphics.hpp>
#include "ConfigHandler.h"

class ProgramMain
{
	sf::RenderWindow window;

	ConfigHandler* config;



public:

	void pgmMain();

	ProgramMain(std::string& configDir);

};

#endif /* PROGRAMMAIN_H */