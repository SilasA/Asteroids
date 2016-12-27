#ifndef GAME_OPTION_STATE_H
#define GAME_OPTION_STATE_H

#include <SFML\Graphics.hpp>
#include <direct.h>

#include "GameState.h"

// Summary:
//
//
class GameOptionState : public GameState
{
private:
public:
	GameOptionState(Game* game);
	~GameOptionState();

	void InitResources() override;
	void Update(sf::Event& event) override;
	void Draw(sf::RenderWindow& window) override;
	void SaveState() override;
	void LoadState() override;
};

#endif // GAME_OPTION_STATE_H