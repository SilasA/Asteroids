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
#ifndef RESOURCE_HANDLER_H
#define RESOURCE_HANDLER_H

#include <map>

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#define NO_USE 0
#define IDLE 1
#define IN_USE 2

// Summary:
//	A wrapper for Graphic or Sound resources
//		
// m_inUse is whether it is needed anymore; when false, it will be 
// destroyed by the handler.  When the wrapped resource is accessed it will 
// return a pointer.
template<typename T>
class Resource
{
private:
	BOOL m_inUse;

public:
	T m_resource;

	bool IsInUse() { return !!m_inUse; }
	bool InUse(BOOL inuse) { m_inUse = inuse; }

	T* GetResource() { return m_resource; }

	Resource<T>& operator=(const Resource<T>& resource) 
	{ 
		std::swap(resource);
		return *this; 
	}

	// Constructs from new object and defaults to in use.
	Resource(T* resource) :
		 m_resource(resource),
		 m_inUse(IN_USE)
	{
	}
	~Resource()
	{
	}
};


// Iterators
typedef std::map<std::string, Resource<sf::Sprite>>::iterator GResMap_it;
typedef std::map<std::string, Resource<sf::Sound>>::iterator SResMap_it;

// Resource types
typedef Resource<sf::Sprite> RGraphic;
typedef Resource<sf::Sound> RSound;

// Summary:
//	A handler for resources
//
//	Two different maps contain Graphic and Sound resources.  The wrapped
// resource within the resource is publicly accessible, but the entire wrapper
// is not.
//
// NOTE: NEVER USE "delete" ON AN ACCESSED OBJECT'S POINTER
class ResourceHandler
{
private:
	static void destroy_resources();
	static void destroy_not_in_use();
	static void destroy_sound_resources();
	static void destroy_graphic_resources();

	static std::map<std::string, RGraphic> m_graphicResources;
	static std::map<std::string, RSound> m_soundResources;

public:
	ResourceHandler();
	~ResourceHandler();	// Destroys all

	// Add a resource to the map
	// NOTE: This will replace the resource if the ID already exists
	static void AddResource(std::string id, RGraphic& resource);
	static void AddResource(std::string id, RSound& resource);

	// Sets the resource to not be used again 
	static void MakeUseless(const std::string& id);
	// Sets the resource to be disabled but still ready to be used again
	static void MakeIdle(const std::string& id);

	// Returns a pointer to the resource
	static sf::Sprite* GetGraphic(const std::string& id);
	static sf::Sound* GetSound(const std::string& id);

	// Destroys any resources that are not in use
	static void CleanResources();
};

#endif // RESOURCE_HANDLER_H

