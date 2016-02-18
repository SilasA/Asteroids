//

#include <SFML\Graphics.hpp>
#include "ProgramMain.h"


ProgramMain::ProgramMain(std::string& configDir)
{
	config = new ConfigHandler(configDir);

	// Construct other objects that need config variables

	delete config;
}


void ProgramMain::pgmMain()
{
	window.create({ 800, 600 }, "Asteroids");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}