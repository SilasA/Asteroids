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
#include "ResourceHandler.h"

#include <unordered_set>
#include <Logger.h>


std::map<std::string, Resource<sf::Sprite>> ResourceHandler::m_graphicResources;
std::map<std::string, Resource<sf::Sound>> ResourceHandler::m_soundResources;


ResourceHandler::ResourceHandler()
{
}


ResourceHandler::~ResourceHandler()
{
	destroy_resources();
}


void ResourceHandler::destroy_resources()
{
	destroy_graphic_resources();
	destroy_sound_resources();
	Logger::WriteLog(LogType::kINFO, "RES", "all resources destroyed", "log");
}


void ResourceHandler::destroy_not_in_use()
{
	Logger::WriteLog(LogType::kINFO,
		"RES", "destroying all resources not in use...", "log");
	
	// Graphical Resources
	std::unordered_set<std::string> t_ids;
	for (GResMap_it it = m_graphicResources.begin();
		it != m_graphicResources.end();
		++it)
		if (!it->second.IsInUse())
			t_ids.insert(it->first);
	for (auto& id : t_ids)
	{
		m_graphicResources.erase(id);
		Logger::WriteLog(LogType::kINFO,
			"RES", "resource destroyed: " + id, "log");
	}
	t_ids.clear();

	// Sound Resources
	for (SResMap_it it = m_soundResources.begin();
		it != m_soundResources.end();
		++it)
		if (!it->second.IsInUse())
			t_ids.insert(it->first);
	for (auto& id : t_ids)
	{
		m_graphicResources.erase(id);
		Logger::WriteLog(LogType::kINFO,
			"RES", "resource destroyed: " + id, "log");
	}
	t_ids.clear();
}


void ResourceHandler::destroy_sound_resources()
{
	m_graphicResources.clear();
	Logger::WriteLog(LogType::kINFO, "RES", "all graphical resources destroyed", "log");
}


void ResourceHandler::destroy_graphic_resources()
{
	m_soundResources.clear();
	Logger::WriteLog(LogType::kINFO, "RES", "all sound resources destroyed", "log");
}


void ResourceHandler::AddResource(const std::string& id, RGraphic& resource)
{
	m_graphicResources[id] = resource;
}


void ResourceHandler::AddResource(const std::string& id, RSound& resource)
{
	m_soundResources[id] = resource;
}


void ResourceHandler::MakeUseless(const std::string& id)
{
	if (m_graphicResources.find(id) != m_graphicResources.end())
		m_graphicResources[id].InUse(NO_USE);
	if (m_soundResources.find(id) != m_soundResources.end())
		m_soundResources[id].InUse(NO_USE);
}


void ResourceHandler::MakeIdle(const std::string& id)
{
	if (m_graphicResources.find(id) != m_graphicResources.end())
		m_graphicResources[id].InUse(IDLE);
	if (m_soundResources.find(id) != m_soundResources.end())
		m_soundResources[id].InUse(IDLE);
}


sf::Sprite* ResourceHandler::GetGraphic(const std::string& id)
{
	if (m_graphicResources.find(id) != m_graphicResources.end()) return nullptr;
	m_graphicResources[id].InUse(true);
	return m_graphicResources[id].GetResource();
}


sf::Sound* ResourceHandler::GetSound(const std::string& id)
{
	if (m_soundResources.find(id) != m_soundResources.end()) return nullptr;
	m_soundResources[id].InUse(true);
	return m_soundResources[id].GetResource();
}


void ResourceHandler::CleanResources()
{
	destroy_not_in_use();
	Logger::WriteLog(LogType::kINFO, "RES", "resources were cleaned", "log");
}
