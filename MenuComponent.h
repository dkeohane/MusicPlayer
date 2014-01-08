#ifndef MENUCOMPONENT_H_
#define MENUCOMPONENT_H_

#include "Global.h"

class MenuComponent
{
public:
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void onCurrentlySelected() = 0;
	virtual void notCurrentlySelected() = 0;

	// Accessors
	virtual sf::Vector2f getPosition() = 0;
	virtual float getWidth() = 0;
	virtual float getHeight() = 0;
	virtual string getDescription(){ return this->description; }

	// Mutators
	virtual void setPosition(sf::Vector2f& position) = 0;
	virtual void setDescription(string& description){ this->description = description; }

private:
	std::string description;
};

#endif