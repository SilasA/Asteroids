#include "GameStatState.h"

#include <pugixml.hpp>

GameStatState::GameStatState(Game* game) :
    GameState(game, "Stats")
{
}

GameStatState::~GameStatState()
{
}

void GameStatState::Draw(std::shared_ptr<sf::RenderWindow> window)
{
}

void GameStatState::Update(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_game->Pop();
}

void GameStatState::InitResources()
{
}

void GameStatState::SaveState(std::shared_ptr<Persistance> persistance)
{
    persistance->GetCurrentSave()->remove_child(TAG.c_str());
    pugi::xml_node stats = persistance->GetNode(TAG.c_str());

    SaveStats(stats, Resources::GetInstance()->highScore);
    SaveStats(stats, Resources::GetInstance()->currentScore);
}

void GameStatState::LoadState(std::shared_ptr<Persistance> persistance)
{
    Ptr(stats_t, stats) = Resources::GetInstance()->highScore;
    pugi::xml_node nStats = persistance->GetNode(TAG.c_str()).child(stats->name);
    pugi::xml_node enemy = nStats.child("enemy");
    pugi::xml_node self = nStats.child("self");

    fill_stats(stats,
        stats->name,
        nStats.attribute("score").as_int(),
        nStats.attribute("level").as_int(),
        enemy.attribute("damage").as_int(),
        enemy.attribute("destroyed").as_int(),
        self.attribute("damage").as_int(),
        self.attribute("lasers").as_int(),
        self.attribute("powerups").as_int());

    m_highStats = stats;

    stats = Resources::GetInstance()->currentScore;
    nStats = persistance->GetNode(TAG.c_str()).child(stats->name);
    enemy = nStats.child("enemy");
    self = nStats.child("self");

    fill_stats(stats,
        stats->name,
        nStats.attribute("score").as_int(),
        nStats.attribute("level").as_int(),
        enemy.attribute("damage").as_int(),
        enemy.attribute("destroyed").as_int(),
        self.attribute("damage").as_int(),
        self.attribute("lasers").as_int(),
        self.attribute("powerups").as_int());

    m_currentStats = stats;
}

void GameStatState::SaveStats(pugi::xml_node& parent, std::shared_ptr<stats_t> stats)
{
    pugi::xml_node stat = parent.append_child(stats->name);
    stat.append_attribute("score").set_value(stats->score);
    stat.append_attribute("level").set_value(stats->level);
    // Enemy
    pugi::xml_node enemy = stat.append_child("enemy");
    enemy.append_attribute("damage").set_value(stats->enemiesDamage);
    enemy.append_attribute("destroyed").set_value(stats->enemiesDestroyed);
    // Self
    pugi::xml_node self = stat.append_child("self");
    self.append_attribute("damage").set_value(stats->damage);
    self.append_attribute("lasers").set_value(stats->lasersShot);
    self.append_attribute("powerups").set_value(stats->powerups);
}