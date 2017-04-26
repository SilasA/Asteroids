#ifndef GAME_STAT_STATE_H
#define GAME_STAT_STATE_H

#include "GameState.h"

#include <string>

// Summary:
//
class GameStatState : public GameState
{
private:
    const std::string TAG = "stats";

    // High score
    std::shared_ptr<stats_t> m_highStats;

    // Current game
    std::shared_ptr<stats_t> m_currentStats;

public:
    GameStatState(Game* game);
    ~GameStatState();

    void Draw(std::shared_ptr<sf::RenderWindow> window) override;
    void Update(sf::Event& event) override;
    void InitResources() override;
    void SaveState(std::shared_ptr<Persistance> persistance) override;
    void LoadState(std::shared_ptr<Persistance> persistance) override;

    void SaveStats(pugi::xml_node& parent, std::shared_ptr<stats_t> stats);
};

#endif // GAME_STAT_STATE_H