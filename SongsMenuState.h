#ifndef SONGSMENUSTATE_H_
#define SONGSMENUSTATE_H_

#include "MenuState.h"
#include "PlaySongCompVisitor.h"
#include "AddSongCompVisitor.h"

class SongsMenuState : public MenuState
{
public:
	SongsMenuState();
	~SongsMenuState();

	void Draw(sf::RenderWindow& window);

	void MenuUp();
	void MenuDown();
	void MakeSelection();
	void Back(){ this->notify(); }

	string getValue(){ return "MainMenu"; }

	void updateMenuEntryLocations(sf::RenderWindow& window);

private:
	void createSongs();
	void createSongsAndBandsList(string s, string delimiter);
	void setupMenuComponents();

	// Functions for moving between and playing songs
	void playSong();
	void upSelection();
	void downSelection();

	typedef void (SongsMenuState::*MenuCompFunctions)(void);

	sf::Texture songsLayoutTexture;
	sf::Sprite songsLayoutSprite;

	// Composite of songs and their visitors
	I_SongComponent* mySongs;
	PlaySongCompVisitor songPlayer;
	AddSongCompVisitor songAdder;

	// index of the currently highlighted song
	int currentSelectedSongIndex;
	// Name of the song currently playing
	string currentlyPlaying;

	// songs and bands list
	std::vector<MenuComponent*> songsList;
	std::vector<MenuComponent*> bandsList;

	std::vector<MenuComponent*> keys; // Keys for the menuComponents mapping
	std::map<MenuComponent*, SongsMenuState::MenuCompFunctions> menuComponents;
	std::map<MenuComponent*, SongsMenuState::MenuCompFunctions>::iterator componentIterator;
};
#endif