#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "MenuState.h"

class MainMenuState : public MenuState
{
public:
	MainMenuState();
	~MainMenuState();

	void Draw(sf::RenderWindow& window);

	void MenuUp();
	void MenuDown();
	void MakeSelection();
	void Back();

	void addMenuComponent(MenuComponent* menuComponent);
	void updateMenuEntryLocations(sf::RenderWindow& window);
	string getValue();

private:
	void setupMenuComponents();

	std::vector<MenuComponent*> menuComponents;
	std::vector<MenuComponent*>::iterator componentIterator;
};
#endif