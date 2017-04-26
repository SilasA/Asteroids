///////////////////////////////////////////////////////////////////////////////
//
// Asteroids - A clone of the immensely popular game by the same title
//				mixed with an equally popular game Galaga.
// version 0.0.1
// author: Silas Agnew <agnewsilas@gmail.com>
//
// Created for a Showcase Project for CACC Programming and Mobile Applications
// class with SFML - Simple and Fast Multimedia Library
//
// This software can be used freely as open-source software with proper
// representation of the author and following SFML's terms of use.
//
// Improper representation may result in the following
//
//	- Disembowelment / forced Seppuku
//	- Smashing of the culprit's knees, ankles, or other vital joints
//	- Severing of the culprit's limb(s)
//	- RKO
//  - 360 no-scope(s)
//
// Beware: These punishments will be enforced 95% of the time 35% of the time
//
///////////////////////////////////////////////////////////////////////////////
#ifndef RESOURCES_H
#define RESOURCES_H

#include "Ship.h"

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <pugixml.hpp>
#include <direct.h>
#include <memory>

#define Ptr(t, name) std::shared_ptr<t> name

// Stats structure
typedef struct
{
    const char* name;
    int score;
    int level;

    // Enemies
    int enemiesDestroyed;
    int enemiesDamage;

    // Self
    int damage;
    int lasersShot;
    int powerups;
} stats_t;

inline void fill_stats(
    std::shared_ptr<stats_t> stats,
    const char* name,
    int score,
    int level,
    int eDestroyed,
    int eDamage,
    int damage,
    int lasersShot,
    int powerups)
{
    stats->score = score;
    stats->level = level;
    stats->enemiesDestroyed = eDestroyed;
    stats->enemiesDamage = eDamage;
    stats->damage = damage;
    stats->lasersShot = lasersShot;
    stats->powerups = powerups;
}

// Summary:
//	A container for resources
class Resources
{
public:
    std::string rootDir;
    std::string graphicDir;
    std::string soundDir;
    std::string textDir;

    //-------------------------------------------------------------------------
    // Graphic

    // Play
    Ptr(sf::Sprite, spBackground);
    Ptr(sf::Sprite, spBackgroundB);
    Ptr(sf::Sprite, spShip);

    // Menu
    //Ptr(sf::Sprite, spBackground)
    Ptr(sf::Sprite, menuBtn1);
    Ptr(sf::Sprite, menuBtn2);
    Ptr(sf::Sprite, menuBtn3);
    Ptr(sf::Sprite, menuBtn4);

    //-------------------------------------------------------------------------
    // Text
    Ptr(sf::Text, tTitle);

    //-------------------------------------------------------------------------
    // Sound
    Ptr(sf::Sound, soImpact);
    Ptr(sf::Music, mMenuSong);

    //-------------------------------------------------------------------------
    // Game
    Ptr(Ship, ship);

    Ptr(stats_t, highScore);
    Ptr(stats_t, currentScore);

    Resources(const std::string& root)
    {
        rootDir = root;
        graphicDir = rootDir + "graphic/";
        soundDir = rootDir + "sounds/";
        textDir = rootDir + "text/";
    }

    static std::shared_ptr<Resources> GetInstance()
    {
        static std::shared_ptr<Resources> r = std::make_shared<Resources>("./Assets/default/"); // default for now
        return r;
    }
};

typedef std::shared_ptr<Resources> pRes;

#endif // RESOURCES_H