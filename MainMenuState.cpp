#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
	currentlySelected = 0;

	setupMenuComponents();

	backgroundTexture.loadFromFile("Media/Images/MainMenuBackground.jpg");
	this->backgroundSprite.setTexture(backgroundTexture);

	if(menuComponents.size() > 0)
		menuComponents.at(currentlySelected)->onCurrentlySelected();
}

void MainMenuState::MenuUp()
{
	decrementComponentList(menuComponents, currentlySelected);
}

void MainMenuState::MenuDown()
{
	incrementComponentList(menuComponents, currentlySelected);
}

void MainMenuState::MakeSelection()
{
	notify();
}

void MainMenuState::Draw(sf::RenderWindow& window)
{
	MenuState::Draw(window);
	for(componentIterator = menuComponents.begin(); componentIterator != menuComponents.end(); componentIterator++)
	{
		(*componentIterator)->Draw(window);
	}
}

void MainMenuState::Back()
{
	cout << "Back Pressed" << endl;
}

// Adds additional menu components to the list
void MainMenuState::addMenuComponent(MenuComponent* menuComponent)
{
	this->menuComponents.push_back(menuComponent);
}

// Used to allign the menu components in the centre of the screen automatically
void MainMenuState::updateMenuEntryLocations(sf::RenderWindow& window)
{
	componentPosition = sf::Vector2f(0.0f, float(window.getSize().y) / menuComponents.size());
	for(componentIterator = menuComponents.begin(); componentIterator != menuComponents.end(); componentIterator++)
	{
		this->componentPosition.x = (window.getSize().x - (*componentIterator)->getWidth()) / 2;
		(*componentIterator)->setPosition(componentPosition);
		this->componentPosition.y += (window.getSize().y / (menuComponents.size() * 2));
	}
}

// Get the value of interest for the observer
string MainMenuState::getValue()
{
	if(menuComponents.size() > 0)
	{
		return menuComponents.at(currentlySelected)->getDescription();
	}else{
		return "Invalid.... Time to break";
	}
}

void MainMenuState::setupMenuComponents()
{
	sf::Font f;
	f.loadFromFile("Media/Fonts/font1.ttf");
	addMenuComponent(MenuComponentBuilder::getInstance()->createMenuComponentText(string("Show Songs"),
																				  sf::Color::Green,
																				  sf::Color::White,
																				  f, 24,
																				  string("SongsMenu")));

	addMenuComponent(MenuComponentBuilder::getInstance()->createMenuComponentText(string("Quit"),
																				  sf::Color::Green,
																				  sf::Color::White,
																				  f, 24,
																				  string("Quit")));

	menuComponents.at(0)->setPosition(sf::Vector2f(500.0f, 650.0f));
	menuComponents.at(1)->setPosition(sf::Vector2f(750.0f, 650.0f));
}