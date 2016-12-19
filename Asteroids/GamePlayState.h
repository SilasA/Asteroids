#ifndef GAME_PLAY_STATE_H
#define GAME_PLAY_STATE_H

#include <SFML\Graphics.hpp>

#include "GameState.h"

// Summary:
//
//
class GamePlayState : public GameState
{
private:

public:
	GamePlayState(Game* game, const std::string& id);

	void InitResources() override;
	void Update(sf::Event& event) override;
	void Draw(sf::RenderWindow& window) override;
	void SaveState() override;
	void LoadState() override;
};

#endif // GAME_PLAY_STATE_H