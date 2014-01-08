#ifndef MENUCOMPONENTTEXT_H_
#define MENUCOMPONENTTEXT_H_

#include "MenuComponent.h"

class MenuComponentText: public MenuComponent
{
public:
	MenuComponentText(){};
	~MenuComponentText(){ delete this; }

	virtual void Draw(sf::RenderWindow& window){ window.draw(componentText); }
	virtual void onCurrentlySelected();
	virtual void notCurrentlySelected();


	// Accessors
	virtual sf::Vector2f getPosition(){ return componentText.getPosition(); }
	virtual float getWidth();
	virtual float getHeight();

	// Mutators
	virtual void setPosition(sf::Vector2f& position){ componentText.setPosition(position); }
	void setSelectedColour(sf::Color color){ selectedColor = color; }
	void setDeselectedColour(sf::Color color){ deselectedColor = color; }
	void setFont(string& filePath);
	void setFont(const sf::Font &font);
	void setDisplayText(string& displayText){ componentText.setString(displayText); }
	void setCharSize(int size){ componentText.setCharacterSize(size); }
	void setCurrentColour(bool selected);

private:
	sf::Font componentFont;
	sf::Text componentText;
	sf::Color selectedColor;
	sf::Color deselectedColor;

};

#endif