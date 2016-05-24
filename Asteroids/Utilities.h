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

#ifndef UTILITIES_H
#define UTILITIES_H

#include <direct.h>
#include <stdio.h>

// Finds the size of an array
#define _ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))

// Puts the current directory of the .exe into a char array
char _dir[FILENAME_MAX];
#define _PROGRAM_DIR(array) (_getcwd(array, sizeof(array)))

#undef ERROR

#endif // UTILITIES_H