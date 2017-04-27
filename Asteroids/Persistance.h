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
