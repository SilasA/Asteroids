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

#include "Logger.h"

#include <string>

#define _P Player::

// \brief
//
//
//
class Player
{
private:

	// \brief The players statistics
	struct PlayerInfo
	{
		int lives;
		int hp; 
		int score = 0;
		int asteroidsDestroyed = 0;
		int shotsFired = 0;
	} playerInfo;

public:

	///////////////////////////////////////////////////////////////////////////
	// GETTERS & SETTERS
	///////////////////////////////////////////////////////////////////////////

	// \return The player's remaining lives
	int getPlayerLives() { return playerInfo.lives; }

	// \return The players remaining health
	int getPlayerHP() { return playerInfo.hp; }

	// \return The player's score
	int getPlayerScore() { return playerInfo.score; }

	// \return How many asteroids the player has destroyed
	int getAsteroidsDestroyed() { return playerInfo.asteroidsDestroyed; }

	// \return How many shots the player has fired
	int getShotsFired() { return playerInfo.shotsFired; }

	// \brief Increments the player's amount of lives
	void addLife() { playerInfo.lives++; }

	// \param hp The new HP of the player
	void setHP(int hp) { playerInfo.hp = hp; }

	// \param score New player score
	void setPlayerScore(int score) { playerInfo.score = score; }

	// \param points Points to add to the score
	void addPlayerScore(int points) { playerInfo.score += points; }

	// \brief Increments the amount of asteroids destroyed
	void asteroidDestroyed() { playerInfo.asteroidsDestroyed++; }

	// \brief Increments the amount of shots fired
	void shotFired() { playerInfo.shotsFired++; }

	///////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	///////////////////////////////////////////////////////////////////////////

	// \param life How many lives the player has
	Player(int life, int hp);
};