#include "GameMenuState.h"
#include "Resources.h"
#include "GamePlayState.h"
#include "GameOptionState.h"
#include <pugixml.hpp>

GameMenuState::GameMenuState(Game* game) :
    GameState(game, "Main Menu")
{
}

GameMenuState::~GameMenuState()
{
    m_buttons.clear();
}

void GameMenuState::InitResources()
{
    m_res->menuBtn1 = std::make_shared<sf::Sprite>(load_texture(m_res->graphicDir + "menu_button.png"));
    m_res->menuBtn2 = std::make_shared<sf::Sprite>(load_texture(m_res->graphicDir + "menu_button.png"));
    m_res->menuBtn3 = std::make_shared<sf::Sprite>(load_texture(m_res->graphicDir + "menu_button.png"));
    m_res->menuBtn4 = std::make_shared<sf::Sprite>(load_texture(m_res->graphicDir + "menu_button.png"));

    int btnW = m_res->menuBtn1->getTextureRect().width;
    int btnH = m_res->menuBtn1->getTextureRect().height;
    int x = (m_game->GetWindow()->getSize().x / 2) - m_res->menuBtn1->getTextureRect().width / 2;
    int add = m_game->GetWindow()->getSize().y / 5;
    int y = add;

    m_buttons.clear();

    m_buttons.push_back(Clickable("btn_newgame", m_res->menuBtn1, sf::IntRect{ x, y, btnW, btnH },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::Blue); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::White); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { g->Push(new GamePlayState(g, "Game Play")); }));
    y += add;
    m_buttons.push_back(Clickable("btn_loadgame", m_res->menuBtn2, sf::IntRect{ x, y, btnW, btnH },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::Blue); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::White); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { g->Push(new GamePlayState(g, "Game Play")); }));
    y += add;
    m_buttons.push_back(Clickable("btn_options", m_res->menuBtn3, sf::IntRect{ x, y, btnW, btnH },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::Blue); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::White); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { g->Push(new GameOptionState(g)); }));
    y += add;
    m_buttons.push_back(Clickable("btn_exit", m_res->menuBtn4, sf::IntRect{ x, y, btnW, btnH },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::Blue); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { s->setColor(sf::Color::White); },
        [](std::shared_ptr<sf::Sprite> s, Game* g) { g->Pop(); }));
}

void GameMenuState::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    for (std::vector<Clickable>::iterator it = m_buttons.begin(); it != m_buttons.end(); ++it)
    {
        it->Draw(window);
    }
}

void GameMenuState::Update(sf::Event& event)
{
    for (std::vector<Clickable>::iterator it = m_buttons.begin(); it != m_buttons.end(); ++it)
    {
        it->Update(m_game->GetWindow(), event, m_game);
    }
}

void GameMenuState::SaveState(std::shared_ptr<Persistance> persistance)
{
}

void GameMenuState::LoadState(std::shared_ptr<Persistance> persistance)
{
}