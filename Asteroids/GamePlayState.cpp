#include "GamePlayState.h"
#include "Resources.h"
#include "MessageBox.h"

GamePlayState::GamePlayState(Game* game) :
    GameState(game, "Play")
{
}

void GamePlayState::InitResources()
{
    // ship
    if (!m_tex1.loadFromFile(m_res->graphicDir + "ship.png"))
        m_log->WriteLog(LogType::kWARNING, Id(), "Unable to load ship.png", "log");
    m_res->spShip = std::make_shared<sf::Sprite>(m_tex1);

    // bg1
    if (!m_tex2.loadFromFile(m_res->graphicDir + "background_b.png"))
        m_log->WriteLog(LogType::kWARNING, Id(), "Unable to load background_b.png", "log");
    m_res->spBackground = std::make_shared<sf::Sprite>(m_tex2);

    // bg2
    if (!m_tex3.loadFromFile(m_res->graphicDir + "background_f.png"))
        m_log->WriteLog(LogType::kWARNING, Id(), "Unable to load background_f.png", "log");
    m_res->spBackgroundB = std::make_shared<sf::Sprite>(m_tex3);

    int x = (m_game->GetWindow()->getSize().x / 2) - m_res->spShip->getTextureRect().width / 2;
    int y = (m_game->GetWindow()->getSize().y) - m_res->spShip->getTextureRect().height / 2;
    m_res->ship = std::make_shared<Ship>(m_res->spShip, sf::IntRect{ x, y, m_res->spShip->getTextureRect().width / 2, m_res->spShip->getTextureRect().height / 2 });
    m_ship = m_res->ship;
    m_background = m_res->spBackground;
    m_backgroundB = m_res->spBackgroundB;

    Resources::GetInstance()->font.loadFromFile(Resources::GetInstance()->textDir + "comic.ttf");
}

void GamePlayState::Update(sf::Event& event)
{
    m_ship->Update(m_game->GetWindow(), event, m_game);
    MessageBox::UpdateAll(m_game->GetWindow(), event, m_game);
}

void GamePlayState::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*m_background.get());
    window->draw(*m_backgroundB.get());
    m_ship->Draw(window);
    MessageBox::DrawAll(window);
}

void GamePlayState::SaveState(std::shared_ptr<Persistance> persistance)
{
    KeyBinds::GetInstance()->SaveState(persistance);
}

void GamePlayState::LoadState(std::shared_ptr<Persistance> persistance)
{
    KeyBinds::GetInstance()->LoadState(persistance);
}