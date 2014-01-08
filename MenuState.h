#ifndef MENUSTATE_H_
#define MENUSTATE_H_

#include "I_State.h"
#include "I_Subject.h"

#include "MenuComponentBuilder.h"

class MenuState:  public I_State, public I_Subject
{
public:
	~MenuState();

	virtual void Draw(sf::RenderWindow& window);

	// Menu functions to be called by command pattern
	virtual void MenuUp() = 0;
	virtual void MenuDown() = 0;
	virtual void MakeSelection() = 0;
	virtual void Back() = 0;

	void incrementComponentList(vector<MenuComponent*>& mcList, int& currentIndex);
	void decrementComponentList(vector<MenuComponent*>& mcList, int& currentIndex);

	virtual void updateMenuEntryLocations(sf::RenderWindow& window){}
	virtual string getValue(){ return NULL; }

protected:
	virtual void setupMenuComponents(){}

	int currentlySelected;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	sf::Vector2f componentPosition;
};
#endif