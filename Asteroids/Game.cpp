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
#include "Game.h"
#include "GameState.h"


Game::Game() :
	Object("Game"),
	m_window({ 800, 600 }, "Asteroids")
{
	Logger::WriteLog(LogType::kINFO, Id(), "Initialized", "log");
}

bool Game::IsStateChanged(bool reset)
{
	bool stateChanged = m_stateChanged;
	if (reset) m_stateChanged = false;
	return stateChanged;
}

int Game::Main()
{
	while (m_window.isOpen())
	{
		GameState* gs = Peek();
		IsStateChanged(true);

		gs->InitResources();
		
		if (m_isResuming) 
			gs->LoadState();

		sf::Event event;
		while (!IsStateChanged() && gs)
		{
			gs->Update();

			while (m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::EventType::Closed:
					gs->SaveState();
					break;
				case sf::Event::EventType::Resized:
					gs->WindowResized(event);
					break;
				case sf::Event::EventType::MouseMoved:
					gs->ControlMoved(event);
					break;
				case sf::Event::EventType::KeyPressed:
					gs->Presses(event);
					break;
				case sf::Event::EventType::KeyReleased:
					gs->Releases(event);
					break;
				default:
					break;
				}
			}

			m_window.clear();
			gs->Draw(m_window);
			m_window.display();
		}
		if (IsEmpty()) m_window.close();
	}
	return 0;
}

void Game::Push(GameState* gameState)
{
	m_stateChanged = true;
	m_states.push(gameState);
}

void Game::Pop()
{
	m_stateChanged = true;
	delete m_states.top();
	m_states.pop();
}

GameState* Game::Peek()
{
	return m_states.size() > 0 ? m_states.top() : nullptr;
}

