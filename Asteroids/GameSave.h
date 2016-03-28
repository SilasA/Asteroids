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

#ifndef GAMESAVE_H
#define GAMESAVE_H

#include "Game.h"

#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <vector>


// \brief The current state of the save class
//
//	UNSAVED: There are changes that have been made since the last save.
//	SAVED: There has been no changes since the last save.
//  UNABLE: The game cannot save because there was no save name given.
enum class SaveState { UNSAVED, SAVED, UNABLE };


// \brief Handles the saving and loading of the game
//
//	It saves the game by creating a file and writing necessary data to
//	it.  The user can specify what to call their file when they go to save.
//  It will also find and load a save when the program is opened again.
class GameSave
{
private:

	// The prefix of the save file i.e. <prefix><savename> 
	// currently save_<savename>
	static std::string prefix;

	static std::vector<std::string> saveNameCol;

	static SaveState state;

	static std::fstream *gameInfo;

	static std::ofstream *saveFile;

	// \brief Create and formats a save file for use.
	//
	//  It will create and format a save file with the given name. This will
	//  only be called when an entirely new save of a different game is made.
	//
	// \param saveName the name of the save file to create.
	static void create(std::string saveName);

protected:

	// \brief Takes a reference to the game and saves it.
	//
	//	This will call the create method with a default savename and write
	//  data to it.
	//
	// \param game A reference to the current game.
	// \returns If the save was successful.
	static bool save(Game* game);


	// \brief Takes a reference to the game and saves it.
	//
	//	This will call the create method with the passed savename and write
	//  data to it.
	// 
	// \param game A reference to the current game.
	// \param saveName The name of the file the game is to be saved to.
	// \returns If the save was successful.
	static bool save(Game* game, std::string& saveName);


	// \brief Takes the save name to open and load the chosen save.
	//
	//	This will take a save name and will open it. The file's location will
	//  have already been verified by a previous function.
	// 
	// \param saveName the name of the file to be opened after conversion to 
	//		  a directory.
	// \returns A reference to the loaded game.
	static Game load(std::string& saveName);


	// \brief This will read the game info file and determine all of the 
	//		  created saves to prompt the user to select one.
	static void findSaves();
	
	// \brief
	//
	GameSave();
	~GameSave();
};

#endif // GAMESAVE_H