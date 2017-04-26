#ifndef GAME_OPTION_STATE_H
#define GAME_OPTION_STATE_H

#include <SFML\Graphics.hpp>
#include <direct.h>
#include <memory>

#include "Clickable.h"
#include "GameState.h"

// Summary:
//
//
class GameOptionState : public GameState
{
private:
    const std::string TAG = "persistance";

    // Switches
    bool m_smoothing;

    // Sliders
    double m_masterVol;
    double m_musicVol;
    double m_soundFXVol;

    // Res pack
    std::string m_pack;

public:
    GameOptionState(Game* game);
    ~GameOptionState();

    void InitResources() override;
    void Update(sf::Event& event) override;
    void Draw(std::shared_ptr<sf::RenderWindow> window) override;
    void SaveState(std::shared_ptr<Persistance> persistance) override;
    void LoadState(std::shared_ptr<Persistance> persistance) override;
};

#endif // GAME_OPTION_STATE_H