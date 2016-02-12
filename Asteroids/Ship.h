//

#ifndef SHIP_H
#define SHIP_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Error.h"

class Ship : public Animation, public Error
{

public:
	
	//
	Ship();

};

#endif /* SHIP_H */