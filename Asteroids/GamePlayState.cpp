#include "GamePlayState.h"
#include "Resources.h"

GamePlayState::GamePlayState(Game* game, const std::string& id) :
    GameState(game, id)
{
}

void GamePlayState::InitResources()
{
    sf::Texture tex;

    // Ship
    if (!tex.loadFromFile(m_res->graphicDir + "ship.png"))
        m_log->WriteLog(LogType::kWARNING, Id(), "Unable to load ship.png", "log");
    m_res->spShip = std::make_shared<sf::Sprite>(tex);

    // bg1
    if (!tex.loadFromFile(m_res->graphicDir + "background_b.png"))
        m_log->WriteLog(LogType::kWARNING, Id(), "Unable to load background_b.png", "log");
    m_res->spBackground = std::make_shared<sf::Sprite>(tex);

    // bg2
    if (!tex.loadFromFile(m_res->graphicDir + "background_f.png"))
        m_log->WriteLog(LogType::kWARNING, Id(), "Unable to load background_f.png", "log");
    m_res->spBackgroundB = std::make_shared<sf::Sprite>(tex);

    int x = (m_game->GetWindow()->getSize().x / 2) - m_res->spShip->getTextureRect().width / 2;
    int y = (m_game->GetWindow()->getSize().y) - m_res->spShip->getTextureRect().height;
    m_res->ship = std::make_shared<Ship>(m_res->spShip, sf::IntRect{ x, y, m_res->spShip->getTextureRect().width, m_res->spShip->getTextureRect().height });
    m_ship = m_res->ship;
    m_background = m_res->spBackground;
    m_backgroundB = m_res->spBackgroundB;
}

void GamePlayState::Update(sf::Event& event)
{
}

void GamePlayState::Draw(std::shared_ptr<sf::RenderWindow> window)
{
}

void GamePlayState::SaveState(std::shared_ptr<Persistance> persistance)
{
}

void GamePlayState::LoadState(std::shared_ptr<Persistance> persistance)
{
}