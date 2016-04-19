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

std::string _GS prefix;
std::vector<std::string> _GS saveNameCol;
SaveState _GS state;
//std::fstream *_GS gameInfo;
//std::fstream *_GS saveFile;


_GS GameSave()
{
	prefix = "save_";
}


_GS ~GameSave()
{
}


void _GS create(std::string saveName)
{
	std::string name = prefix + saveName + ".dat";

	//_GS saveFile->open(_SAVE_DIR + name, std::ios::out);
}

/*
bool _GS save(Game* game)
{
	if (_GS saveFile == nullptr)
	{
		create(_DEFAULT_SAVE);
		return true;
	}
	return false;
}
*/

bool _GS save(Game* game, std::string& saveName)
{
	return false;
}


Game _GS load(std::string& saveName)
{
	Game game;
	return game;
}


void _GS findSaves()
{

}