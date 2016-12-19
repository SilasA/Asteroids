#include "GamePlayState.h"

GamePlayState::GamePlayState(Game* game, const std::string& id) :
	GameState(game, id)
{
}

void GamePlayState::InitResources()
{
}

void GamePlayState::Update(sf::Event& event)
{
}

void GamePlayState::Draw(sf::RenderWindow& window)
{
}

void GamePlayState::SaveState()
{
}

void GamePlayState::LoadState()
{
}
