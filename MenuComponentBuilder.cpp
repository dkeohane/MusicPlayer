#include "MenuComponentBuilder.h"

MenuComponentBuilder* MenuComponentBuilder::getInstance()
{
	static MenuComponentBuilder instance;
	return &instance;
}

MenuComponent* MenuComponentBuilder::createMenuComponentTexture(string& selectFilepath,
																string& deselectFilepath,
																string& description)
{
	MenuComponentTexture* mct = new MenuComponentTexture();
	mct->setDescription(description);
	mct->setSelectedTexture(selectFilepath);
	mct->setDeselectedTexture(deselectFilepath);
	mct->setSize();
	mct->setCurrentTexture(false);
	return mct;
}


MenuComponent* MenuComponentBuilder::createMenuComponentText(string& displayText,
														     sf::Color selectedColor,
														     sf::Color deselectedColor,
															 sf::Font& font,
															 int charSize,
														     string& description)
{
	MenuComponentText* mct = new MenuComponentText();
	mct->setDescription(description);
	mct->setDisplayText(displayText);
	mct->setSelectedColour(selectedColor);
	mct->setDeselectedColour(deselectedColor);
	mct->setFont(font);
	mct->setCharSize(charSize);
	mct->setCurrentColour(false);
	return mct;
}
