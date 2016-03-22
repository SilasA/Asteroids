//

#include <SFML\Graphics.hpp>
#include "stdafx.h"
#include "ProgramMain.h"


ProgramMain::ProgramMain(std::string& configDir) : ConfigHandler(configDir)
{
	// No file to specify so set to null
	logFile = nullptr;

	isLog = false;
	logger = new std::thread(&ProgramMain::log, "");
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

	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	*logFile << "Asteroids Log Info" << std::endl;
	*logFile << now->tm_year << ":" << now->tm_mon << ":" << now->tm_mday <<
		":" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec <<
		std::endl;
	*logFile << "-------------------------------------------------------" <<
		std::endl;

	while (isLog)
	{
		// Time
		*logFile << now->tm_year << ":" << now->tm_mon << ":" << now->tm_mday <<
			":" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec <<
			std::endl;

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