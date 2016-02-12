//

#include <SFML\Graphics.hpp>
#include "ProgramMain.h"


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