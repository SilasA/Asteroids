#ifndef GAME_PLAY_STATE_H
#define GAME_PLAY_STATE_H

#include <SFML\Graphics.hpp>

#include "Resources.h"
#include "GameState.h"
#include "Ship.h"

// Summary:
//
//
class GamePlayState : public GameState
{
private:
    const std::string TAG = "game";

    Ptr(sf::Sprite, m_backgroundB); // Back
    Ptr(sf::Sprite, m_background); // Front

    Ptr(Ship, m_ship);

    int m_level;

public:
    GamePlayState(Game* game);

    void InitResources() override;
    void Update(sf::Event& event) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;
    void SaveState(std::shared_ptr<Persistance> persistance) override;
    void LoadState(std::shared_ptr<Persistance> persistance) override;
};

#endif // GAME_PLAY_STATE_H