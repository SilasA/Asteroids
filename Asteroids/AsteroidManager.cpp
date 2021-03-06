#include "AsteroidManager.h"
#include "Resources.h"

AsteroidManager::AsteroidManager(const sf::Texture& tex, float spawnTime, int maxVisible, int total) :
    Object("Asteroid Manager"),
    m_asteroid(tex), m_spawnTime(spawnTime), m_maxVisible(maxVisible), m_total(total)
{
    if (m_asteroid.loadFromFile(Resources::GetInstance()->graphicDir + "asteroid.png"))
        m_log->WriteLog(LogType::kWarning, Id(), "unable to load file asteroid.png");

    m_timer.restart();

    srand(time(NULL));
}

AsteroidManager::~AsteroidManager()
{
}

void AsteroidManager::add_asteroid(sf::Vector2f startPos)
{
    sf::IntRect rect{
        (int)(startPos.x - m_asteroid.getSize().x / 2),
        (int)(startPos.y - m_asteroid.getSize().y / 2),
        (int)m_asteroid.getSize().x,
        (int)m_asteroid.getSize().y };
    m_asteroids.emplace_back(std::make_unique<Asteroid>(m_asteroidName + std::to_string(m_suffix++), std::make_shared<sf::Sprite>(m_asteroid), rect));
}

void AsteroidManager::remove_asteroid(std::string& id)
{
    for (std::list<std::unique_ptr<Asteroid>>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
    {
        if ((*it)->Id() == id)
        {
            m_asteroids.erase(it);
            break;
        }
    }
}

sf::Vector2f AsteroidManager::get_rand_position(int xMax, int xMin)
{
    return sf::Vector2f(rand() % xMin + xMax, SPAWN_Y);
}

void AsteroidManager::Update(std::shared_ptr<sf::RenderWindow> window, sf::Event& event, Game* game)
{
    // Finished Check
    if (!m_reachedTotal)
        m_reachedTotal = m_spawned >= 10;
    else if (m_asteroids.size() <= 0)
    {
        m_isFinished = true;
    }

    // Spawning
    if (m_timer.getElapsedTime().asSeconds() >= m_spawnTime &&
        !m_reachedTotal && m_visible < m_maxVisible)
    {
        add_asteroid(get_rand_position(SPAWN_BUFFER, game->GetWindow()->getSize().x - SPAWN_BUFFER));
        m_spawned++;
        m_timer.restart();
    }

    m_visible = 0;
    for (std::list<std::unique_ptr<Asteroid>>::iterator a = m_asteroids.begin(); a != m_asteroids.end();)
    {
        if ((*a)->IsShot()) a = m_asteroids.erase(a);
        else
        {
            m_visible++;
            (*a)->Update(window, event, game);
            a++;
        }
    }
}

void AsteroidManager::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    for (std::unique_ptr<Asteroid>& a : m_asteroids)
        a->Draw(window);
}