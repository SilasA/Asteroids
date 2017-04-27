#include "Persistance.h"
#include "Resources.h"

Persistance::Persistance(const std::string& dir) :
    m_dir(dir)
{
    _mkdir(m_dir.c_str());
    std::string path = m_dir + "save.xml";
    pugi::xml_parse_result r = m_currentSave.load_file(path.c_str());
    m_exists = r.status != pugi::status_file_not_found;

    if (m_exists)
    {
        m_currentSaveName = m_currentSave.name();
    }
    else
    {
        m_currentSave.set_name("save");
        if (m_currentSave.empty())
            m_currentSave.append_child(pugi::node_declaration);
    }
    m_usable = true;
}

Persistance::~Persistance()
{
}

std::shared_ptr<Persistance> Persistance::GetInstance()
{
    static std::shared_ptr<Persistance> p = std::make_shared<Persistance>("./Saves/");
    return p;
}

pugi::xml_node Persistance::GetNode(const char* name)
{
    pugi::xml_node n = m_currentSave.child(name);
    if (n.type() != pugi::node_null) return n;
    return GetNewSaveNode(name);
}

pugi::xml_node Persistance::GetNewSaveNode(const char* name, pugi::xml_node_type type)
{
    pugi::xml_node n = m_currentSave.append_child(type);
    n.set_name(name);
    return n;
}

bool Persistance::SaveToFile(const std::string& savename)
{
    std::string path = m_dir + ((savename == "") ? m_currentSaveName + ".xml" : savename + ".xml");
    return m_currentSave.save_file(path.c_str());
}

bool Persistance::LoadFile(const std::string& filename, bool absolute)
{
    std::string path;
    if (!absolute)
        path = m_dir + filename;
    else path = filename;
    return m_currentSave.load_file(path.c_str());
}

void Persistance::LoadDefault()
{
    LoadFile(Resources::GetInstance()->rootDir + "default_save.xml", true);
}
