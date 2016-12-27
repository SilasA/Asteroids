#include "GameMenuState.h"
#include "ResourceHandler.h"
#include "GamePlayState.h"
#include "GameOptionState.h"


GameMenuState::GameMenuState(Game* game) :
	GameState(game, "Main Menu")
{
}

void GameMenuState::InitResources()
{
	ResourceHandler::AddResource("btn_newgame",
		RGraphic(new sf::Sprite(load_texture(".\\assets\\btn_menu.png"))));
	ResourceHandler::AddResource("btn_loadgame",
		RGraphic(new sf::Sprite(load_texture(".\\assets\\btn_menu.png"))));
	ResourceHandler::AddResource("btn_options",
		RGraphic(new sf::Sprite(load_texture(".\\assets\\btn_menu.png"))));
	ResourceHandler::AddResource("btn_exit",
		RGraphic(new sf::Sprite(load_texture(".\\assets\\btn_menu.png"))));

	m_buttons.push_back(Clickable("btn_newgame", ResourceHandler::GetGraphic("btn_newgame"), sf::IntRect{ 0, 0, 0, 0 },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::Blue); },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::White); },
		[](sf::Sprite* s, Game* g) { g->Push(new GamePlayState(g, "Game Play")); }));
	m_buttons.push_back(Clickable("btn_loadgame", ResourceHandler::GetGraphic("btn_loadgame"), sf::IntRect{ 0, 0, 0, 0 },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::Blue); },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::White); },
		[](sf::Sprite* s, Game* g) { g->Push(new GamePlayState(g, "Game Play")); }));
	m_buttons.push_back(Clickable("btn_options", ResourceHandler::GetGraphic("btn_options"), sf::IntRect{ 0, 0, 0, 0 },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::Blue); },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::White); },
		[](sf::Sprite* s, Game* g) { g->Push(new GameOptionState(g)); }));
	m_buttons.push_back(Clickable("btn_exit", ResourceHandler::GetGraphic("btn_exit"), sf::IntRect{ 0, 0, 0, 0 },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::Blue); },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::White); },
		[](sf::Sprite* s, Game* g) { g->Pop(); }));
}

void GameMenuState::Draw(sf::RenderWindow& window)
{
	for (auto& btn : m_buttons)
	{
		btn.Draw(window);
	}
}

void GameMenuState::Update(sf::Event& event)
{
}

void GameMenuState::SaveState()
{
}

void GameMenuState::LoadState()
{
}
