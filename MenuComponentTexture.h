#ifndef MENUCOMPONENTTEXTURE_H_
#define MENUCOMPONENTTEXTURE_H_

#include "MenuComponent.h"

class MenuComponentTexture: public MenuComponent
{
public:
	MenuComponentTexture(){};
	~MenuComponentTexture(){ delete this; }

	virtual void Draw(sf::RenderWindow& window){ window.draw(this->componentBlock); }
	virtual void onCurrentlySelected();
	virtual void notCurrentlySelected();

	// Accessors
	sf::Vector2f getPosition(){ return componentBlock.getPosition(); }
	float getWidth();
	float getHeight();

	// Mutators
	void setPosition(sf::Vector2f& position){ componentBlock.setPosition(position); }
	void setSelectedTexture(string& filepath){ selectedTexture.loadFromFile(filepath); }
	void setDeselectedTexture(string& filepath){ deselectedTexture.loadFromFile(filepath); }
	void setSelectedTexture(sf::Texture texture){ selectedTexture = texture; }
	void setDeselectedTexture(sf::Texture texture){ deselectedTexture = texture; }
	void setSize(); // Uses size of deselected texure as default
	void setSize(sf::Vector2f& size){ componentBlock.setSize(size); }
	void setCurrentTexture(bool selected);
 
private:
	sf::RectangleShape componentBlock;
	sf::Texture selectedTexture;
	sf::Texture deselectedTexture;
};

#endif