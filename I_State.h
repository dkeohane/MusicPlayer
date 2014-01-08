#ifndef I_STATE_H_
#define I_STATE_H_

#include "Global.h"
#include "I_Subject.h"

class I_State
{
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
};
#endif