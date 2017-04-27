#include "GameOptionState.h"

GameOptionState::GameOptionState(Game* game) :
    GameState(game, "Option")
{
}

GameOptionState::~GameOptionState()
{
}

void GameOptionState::InitResources()
{
}

void GameOptionState::Update(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_game->Pop();
}

void GameOptionState::Draw(std::shared_ptr<sf::RenderWindow> window)
{
}

void GameOptionState::SaveState(std::shared_ptr<Persistance> persistance)
{
    persistance->GetCurrentSave()->remove_child(TAG.c_str());
    pugi::xml_node root = persistance->GetNode(TAG.c_str());
    // Graphics
    pugi::xml_node graphic = root.append_child("graphics");
    graphic.append_child("smoothing").append_attribute("state").set_value(m_smoothing);
    // Sounds
    pugi::xml_node sound = root.append_child("sound");
    sound.append_child("volume_master").append_attribute("state").set_value(m_masterVol);
    sound.append_child("volume_music").append_attribute("state").set_value(m_musicVol);
    sound.append_child("volume_soundFx").append_attribute("state").set_value(m_soundFXVol);
    // Resource Pack
    root.append_child("resource_pack").append_attribute("path").set_value(m_pack.c_str());
}

void GameOptionState::LoadState(std::shared_ptr<Persistance> persistance)
{
    pugi::xml_node root = persistance->GetNode(TAG.c_str());
    // Graphics
    pugi::xml_node graphic = root.child("graphics");
    m_smoothing = graphic.child("smoothing").attribute("state").as_bool();
    // Sounds
    pugi::xml_node sound = root.child("sound");
    m_masterVol = sound.child("volume_master").attribute("state").as_double();
    m_musicVol = sound.child("volume_music").attribute("state").as_double();
    m_soundFXVol = sound.child("volume_soundFx").attribute("state").as_double();
    // Resource Pack
    m_pack = root.child("resource_pack").attribute("path").value();
}