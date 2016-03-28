///////////////////////////////////////////////////////////////////////////////
///
/// Asteroids - A clone of the immensely popular game by the same title
///				mixed with an equally popular game Galaga.
/// version 0.0.1
/// author: Silas Agnew <agnewsilas@gmail.com>
///
/// Created for a Showcase Project for CACC Programming and Mobile Applications
/// class with SFML - Simple and Fast Multimedia Library
/// 
/// This software can be used freely as open-source software with proper
/// representation of the author and following SFML's terms of use.
///
/// Improper representation may result in the following
/// 
///	- Disembowelment / forced Seppuku
///	- Smashing of the culprit's knees, ankles, or other vital joints
///	- Severing of the culprit's limb(s)
///	- RKO
/// - 360 no-scope(s)
///
/// Beware: These punishments will be enforced 95% of the time 35% of the time
///
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GameSave.h"


GameSave::GameSave()
{
	prefix = "save_";
}


GameSave::~GameSave()
{
}


void GameSave::create(std::string saveName)
{
	std::string name = prefix + saveName + ".dat";

	saveFile->open("/saves/" + name);
}


bool GameSave::save(Game* game)
{
	if (saveFile == nullptr)
		create("default");

	return false;
}


bool GameSave::save(Game* game, std::string& saveName)
{
	return false;
}


Game GameSave::load(std::string& saveName)
{
	Game game;
	return game;
}


void GameSave::findSaves()
{

}