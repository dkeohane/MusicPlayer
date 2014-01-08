#include "MenuState.h"

void MenuState::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}

MenuState::~MenuState()
{
	//menuComponents.erase(menuComponents.begin(), menuComponents.end());
}

void MenuState::incrementComponentList(vector<MenuComponent*>& mcList, int& currentIndex)
{
	if(mcList.size() > 0)
	{
		mcList.at(currentIndex)->notCurrentlySelected();
		currentIndex++;
	
		if (currentIndex >= int(mcList.size()))
			currentIndex = 0;

		mcList.at(currentIndex)->onCurrentlySelected();
	}
}

void MenuState::decrementComponentList(vector<MenuComponent*>& mcList, int& currentIndex)
{
	if(mcList.size() > 0)
	{
		mcList.at(currentIndex)->notCurrentlySelected();
		currentIndex--;
	
		if (currentIndex < 0)
			currentIndex = mcList.size() - 1;

		mcList.at(currentIndex)->onCurrentlySelected();
	}
}