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


Game& GameSave::load(std::string& saveName)
{
	Game game;
	return game;
}


void GameSave::findSaves()
{

}