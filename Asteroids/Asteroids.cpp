// Asteroids.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window({ 800, 600 }, "Title");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}

