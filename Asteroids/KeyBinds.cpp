#include "KeyBinds.h"

KeyBinds::KeyBinds()
{
}

KeyBinds::~KeyBinds()
{
}

std::shared_ptr<KeyBinds> KeyBinds::GetInstance()
{
    static std::shared_ptr<KeyBinds> k = std::make_shared<KeyBinds>();
    return k;
}

bool KeyBinds::SaveState(std::shared_ptr<Persistance> persistance)
{
    persistance->GetCurrentSave()->remove_child("keys");
    pugi::xml_node keys = persistance->GetNewSaveNode("keys");
    for (std::map<std::string, sf::Keyboard::Key>::iterator it = m_keyMap.begin();
        it != m_keyMap.end(); it++)
    {
        keys.append_child(it->first.c_str()).append_attribute("key").set_value((int)it->second);
    }
    return true;
}

bool KeyBinds::LoadState(std::shared_ptr<Persistance> persistance)
{
    m_keyMap.clear();
    pugi::xml_node keys = persistance->GetNode("keys");
    for (pugi::xml_node_iterator it = keys.begin(); it != keys.end(); it++)
    {
        m_keyMap[it->name()] = (sf::Keyboard::Key)it->attribute("key").as_int();
    }
    return true;
}

sf::Keyboard::Key KeyBinds::GetKey(const std::string& name)
{
    return m_keyMap.find(name)->second;
}

void KeyBinds::SetKey(const std::string& name, sf::Keyboard::Key key)
{
    m_keyMap[name] = key;
}