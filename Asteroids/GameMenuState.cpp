#include "GameMenuState.h"
#include "ResourceHandler.h"
#include "GamePlayState.h"


GameMenuState::GameMenuState(Game* game) :
	GameState(game, "Main Menu")
{
}

void GameMenuState::InitResources()
{
	ResourceHandler::AddResource("btn_ready", 
		RGraphic(new sf::Sprite(load_texture(".\\assets\\btn_ready.png"))));

	m_buttons.push_back(Clickable("btn_ready", ResourceHandler::GetGraphic("btn_ready"), sf::IntRect{ 0, 0, 0, 0 },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::Blue); },
		[](sf::Sprite* s, Game* g) { s->setColor(sf::Color::White); },
		[](sf::Sprite* s, Game* g) { g->Push(new GamePlayState(g, "Game Play")); }));
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
