//

#include <SFML\Graphics.hpp>
#include <ctime>
#include "stdafx.h"
#include "ProgramMain.h"


ProgramMain::ProgramMain(std::string& configDir) : ConfigHandler(configDir)
{
	// No file to specify so set to null
	logFile = nullptr;

	isLog = false;
	logger = new std::thread(&ProgramMain::log, "");

	// Find data
	findSaves();



	setConfig();
	
}


ProgramMain::ProgramMain(std::string& configDir, std::string& logDir) : 
	ConfigHandler(configDir)
{
	isLog = true;
	logger = new std::thread(&ProgramMain::log, logDir);
}


void ProgramMain::log(std::string& logDir)
{
	try
	{
		if (!isLog)
			logFile = new std::ofstream(logDir);
	}
	catch (std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
		isLog = false;
	}

	char buffer[32];
	struct tm newTime;
	__time32_t time;
	_time32(&time);
	_localtime32_s(&newTime, &time);
	asctime_s(buffer, 32, &newTime);

	*logFile << "Asteroids Log Info" << std::endl;
	*logFile << buffer << std::endl;
	*logFile << "Resource Pack: ";
	*logFile << "-------------------------------------------------------" <<
		std::endl;

	while (isLog)
	{
		// Time

		_time32(&time);
		_localtime32_s(&newTime, &time);
		asctime_s(buffer, 32, &newTime);

		*logFile << buffer << std::endl;

		// Put any log info here
		*logFile << "" << std::endl;
		
		// Divider
		*logFile << "-------------------------------------------------------" <<
			std::endl;


		// Execute loop every x seconds
		sf::sleep(sf::seconds(1));
	}

	logFile->close();
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