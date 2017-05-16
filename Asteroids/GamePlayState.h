#ifndef GAME_PLAY_STATE_H
#define GAME_PLAY_STATE_H

#include <SFML\Graphics.hpp>
#include <list>

#include "Resources.h"
#include "GameState.h"
#include "Ship.h"
#include "Indicator.h"
#include "Asteroid.h"

// Summary:
//
//
class GamePlayState : public GameState
{
private:
    const std::string TAG = "game";

    sf::Texture m_tex1;
    sf::Texture m_tex2;
    sf::Texture m_tex3;
    sf::Texture m_astTex;

    Ptr(sf::Sprite, m_backgroundB); // Back
    Ptr(sf::Sprite, m_background); // Front

    Ptr(Ship, m_ship);

    std::list<std::shared_ptr<Asteroid>> m_asteroids;

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