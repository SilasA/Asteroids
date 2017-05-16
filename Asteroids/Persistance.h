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
#ifndef PERSISTANCE_H
#define PERSISTANCE_H

#include <pugixml.hpp>
#include <string>
#include <memory>
#include <mutex>
#include <direct.h>

// Summary:
//
class Persistance
{
private:
    std::string m_dir;
    std::string m_currentSaveName;

    bool m_exists;
    bool m_usable;

    pugi::xml_document m_currentSave;

    std::mutex m_lock;

public:
    Persistance(const std::string& dir);
    ~Persistance();

    static std::shared_ptr<Persistance> GetInstance();

    inline pugi::xml_document* GetCurrentSave() { return &m_currentSave; }

    pugi::xml_node GetNode(const char* name);
    pugi::xml_node GetNewSaveNode(const char* name, pugi::xml_node_type type = pugi::node_element);
    bool SaveToFile(const std::string& savename = "");
    bool LoadFile(const std::string& filename, bool absolute = false);

    void LoadDefault();
};

#endif // PERSISTANCE_H
