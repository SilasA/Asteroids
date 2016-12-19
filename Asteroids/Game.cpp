#include "Game.h"
#include "GameState.h"
#include "GameMenuState.h"


Game::Game() :
	Object("Game"),
	m_window({ 800, 600 }, "Asteroids")
{
	Logger::WriteLog(LogType::kINFO, Id(), "Initialized", "log");
	m_states.push(new GameMenuState(this));
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
			gs->Update(event);

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

