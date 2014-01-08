#include "MenuComponentTexture.h"

float MenuComponentTexture::getHeight()
{
	return this->componentBlock.getSize().y;
}

float MenuComponentTexture::getWidth()
{
	return this->componentBlock.getSize().x; 
}

void MenuComponentTexture::onCurrentlySelected()
{
	this->componentBlock.setTexture(&selectedTexture);
}

void MenuComponentTexture::notCurrentlySelected()
{
	this->componentBlock.setTexture(&deselectedTexture);
}

void MenuComponentTexture::setSize()
{
	// Uses size of deselected texure as default
	componentBlock.setSize(sf::Vector2f(deselectedTexture.getSize().x, deselectedTexture.getSize().y));
}

void MenuComponentTexture::setCurrentTexture(bool selected)
{
	if(selected)
		componentBlock.setTexture(&selectedTexture);
	else
		componentBlock.setTexture(&deselectedTexture);
}