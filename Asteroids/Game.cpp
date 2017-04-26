#include "Game.h"
#include "GameState.h"
#include "GameMenuState.h"

Game::Game() :
    Object("Game"),
    m_window(std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 720), "Asteroids"))
{
    m_log->WriteLog(LogType::kINFO, Id(), "Initialized", "log");
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
    while (m_window->isOpen())
    {
        GameState* gs = Peek();
        IsStateChanged(true);

        gs->InitResources();

        sf::Event event;
        while (!IsStateChanged() && Peek())
        {
            gs->Update(event);

            while (m_window->pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::EventType::Closed:
                    Persistance::GetInstance()->SaveToFile("save");
                    break;
                case sf::Event::EventType::Resized:
                    gs->WindowResized(event);
                default:
                    break;
                }
            }

            if (IsEmpty())
            {
                m_window->close();
                Persistance::GetInstance()->SaveToFile("save");
                break;
            }

            m_window->clear();
            if (gs != nullptr)
                gs->Draw(m_window);
            m_window->display();
        }
        if (gs != nullptr && m_statePopped)
        {
            delete gs;
            m_statePopped = false;
        }
    }
    return 0;
}

void Game::Push(GameState* gameState)
{
    m_stateChanged = true;
    Peek()->SaveState(Persistance::GetInstance());
    Peek()->Deactivate();
    m_states.push(gameState);
    Peek()->Activate();
    Peek()->LoadState(Persistance::GetInstance());
}

void Game::Pop()
{
    m_stateChanged = true;
    m_statePopped = true;
    Peek()->SaveState(Persistance::GetInstance());
    Peek()->Deactivate();
    //delete m_states.top();
    m_states.pop();
    if (!IsEmpty())
    {
        Peek()->Activate();
        Peek()->LoadState(Persistance::GetInstance());
    }
}

GameState* Game::Peek()
{
    return m_states.size() > 0 ? m_states.top() : nullptr;
}