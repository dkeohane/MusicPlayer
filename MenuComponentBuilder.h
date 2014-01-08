#ifndef MENUCOMPONENTBUILDER_H_
#define MENUCOMPONENTBUILDER_H_

#include "MenuComponentText.h"
#include "MenuComponentTexture.h"

class MenuComponentBuilder
{
	
public:
	// Singleton
	static MenuComponentBuilder* getInstance();
	
	// Creates a menu component texture
	MenuComponent* createMenuComponentTexture(string& selectFilepath,
											  string& deselectFilepath,
											  string& description);
	// Creates a menu component text
	MenuComponent* createMenuComponentText(string& displayText,
										   sf::Color selectedColor,
										   sf::Color deselectedColor,
										   sf::Font& font,
										   int charSize,
										   string& description);

private:
	MenuComponentBuilder(){};

};
#endif
