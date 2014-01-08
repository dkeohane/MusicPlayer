#include "MenuComponentText.h"

float MenuComponentText::getHeight()
{
	return this->componentText.getLocalBounds().height;
}

float MenuComponentText::getWidth()
{
	return this->componentText.getLocalBounds().width;
}

void MenuComponentText::onCurrentlySelected()
{
	this->componentText.setColor(selectedColor);
}

void MenuComponentText::notCurrentlySelected()
{
	this->componentText.setColor(deselectedColor);
}

void MenuComponentText::setFont(string& filePath)
{
	componentFont.loadFromFile(filePath);
	componentText.setFont(componentFont);
}

void MenuComponentText::setFont(const sf::Font& font)
{
	componentFont = font;
	componentText.setFont(componentFont);
}

void MenuComponentText::setCurrentColour(bool selected)
{
	if(selected)
		componentText.setColor(sf::Color::White);
	else
		componentText.setColor(sf::Color::White);
}