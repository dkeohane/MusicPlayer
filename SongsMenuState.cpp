#include "SongsMenuState.h"

SongsMenuState::SongsMenuState()
{
	currentlySelected = 0;
	currentSelectedSongIndex = 0;
	currentlyPlaying = "";

	setupMenuComponents();
	createSongs();

	backgroundTexture.loadFromFile("Media/Images/SongsMenuBG.jpg");
	backgroundSprite.setTexture(backgroundTexture);
	songsLayoutTexture.loadFromFile("Media/Images/SongsLayoutBG.png");
	songsLayoutSprite.setTexture(songsLayoutTexture);
	songsLayoutSprite.setPosition(25.0f,50.0f);

	if(menuComponents.size() > 0)
	{
		// Highlights the first MenuComponent
		menuComponents.begin()->first->onCurrentlySelected();
	}

	if(songsList.size() > 0)
	{
		// Hightlights the first song and band
		songsList.at(currentSelectedSongIndex)->onCurrentlySelected();
		bandsList.at(currentSelectedSongIndex)->onCurrentlySelected();
	}

	for(componentIterator = menuComponents.begin(); componentIterator != menuComponents.end(); componentIterator++)
	{
		keys.push_back(componentIterator->first);
	}
}


SongsMenuState::~SongsMenuState()
{
	menuComponents.erase(menuComponents.begin(), menuComponents.end());
}


void SongsMenuState::Draw(sf::RenderWindow& window)
{
	MenuState::Draw(window);
	window.draw(songsLayoutSprite);

	for(unsigned int i = 0; i < keys.size(); i++)
	{
		keys.at(i)->Draw(window);
	}

	// both lists should be the same lenght, but using && just as a precautionary measure
	for(unsigned int i = 0; i < songsList.size() && i < bandsList.size(); i++)
	{
		songsList.at(i)->Draw(window);
		bandsList.at(i)->Draw(window);
	}
}


void SongsMenuState::MenuUp()
{
	decrementComponentList(keys, currentlySelected);
}

void SongsMenuState::MenuDown()
{
	incrementComponentList(keys, currentlySelected);
}

void SongsMenuState::MakeSelection()
{
	componentIterator = menuComponents.find(keys.at(currentlySelected));

	if(componentIterator == menuComponents.end())
	{
		cout << "Cannot find" << endl;
	}else{
		
		// Had to learn function pointers
		// http://msdn.microsoft.com/en-us/library/z72c1dfd(v=vs.110).aspx
		(this->* componentIterator->second)();
	}
}


void SongsMenuState::playSong()
{
	// Nothing is playing yet so can play song instantly
	if(currentlyPlaying == "")
	{
		currentlyPlaying = songsList.at(currentSelectedSongIndex)->getDescription();
		mySongs->accept(songPlayer, currentlyPlaying);
	}
	// Song selected is currently playing, pause it 
	else if(songsList.at(currentSelectedSongIndex)->getDescription() == currentlyPlaying)
	{
		mySongs->accept(songPlayer, songsList.at(currentSelectedSongIndex)->getDescription());
		currentlyPlaying = "";
	}
	// Song selected isn't currently playing and a different song is playing
	else if(songsList.at(currentSelectedSongIndex)->getDescription() != currentlyPlaying)
	{
		// Pause currently playing
		mySongs->accept(songPlayer, currentlyPlaying);

		// Update currentlyPlaying to the new song and then play it
		currentlyPlaying = songsList.at(currentSelectedSongIndex)->getDescription();
		mySongs->accept(songPlayer, currentlyPlaying);
	}
}


void SongsMenuState::upSelection()
{
	decrementComponentList(songsList, currentSelectedSongIndex);

	// Could switch to 2 variables to remove this if statement
	if(currentSelectedSongIndex != int(songsList.size()) - 1)
		currentSelectedSongIndex++;
	else
		currentSelectedSongIndex = 0;

	decrementComponentList(bandsList, currentSelectedSongIndex);
}


void SongsMenuState::downSelection()
{
	incrementComponentList(songsList, currentSelectedSongIndex);

	// Could switch to 2 variables to remove this if statement
	if(currentSelectedSongIndex != 0)
		currentSelectedSongIndex--;
	else
		currentSelectedSongIndex = int(bandsList.size()) - 1;
		
	incrementComponentList(bandsList, currentSelectedSongIndex);
}


void SongsMenuState::updateMenuEntryLocations(sf::RenderWindow& window)
{
	componentPosition = sf::Vector2f(songsLayoutSprite.getPosition().x + 30, float(window.getSize().y) / songsList.size());
	sf::Vector2f componentPosition1 = sf::Vector2f(songsLayoutSprite.getPosition().x + 430, float(window.getSize().y) / bandsList.size());

	for(unsigned int i = 0; i < songsList.size() && i < bandsList.size(); i++)
	{
		songsList.at(i)->setPosition(componentPosition);
		bandsList.at(i)->setPosition(componentPosition1);
		componentPosition.y += (window.getSize().y / (songsList.size() * 2));
		componentPosition1.y += (window.getSize().y / (bandsList.size() * 2));
	}
}


void SongsMenuState::setupMenuComponents()
{
	menuComponents[MenuComponentBuilder::getInstance()->createMenuComponentTexture(string("Media/Images/UpButton.png"),
																					 string("Media/Images/UpButtonD.png"),
																					 string("Up"))] = &SongsMenuState::upSelection;

	menuComponents[MenuComponentBuilder::getInstance()->createMenuComponentTexture(string("Media/Images/PlayButton.png"),
																					 string("Media/Images/PlayButtonD.png"),
																					 string("Play"))] = &SongsMenuState::playSong;

	menuComponents[MenuComponentBuilder::getInstance()->createMenuComponentTexture(string("Media/Images/DownButton.png"),
																					 string("Media/Images/DownButtonD.png"),
																					 string("Down"))] = &SongsMenuState::downSelection;

	// Position menu components
	sf::Vector2f pos = sf::Vector2f(1050, 125);
	componentIterator = menuComponents.begin();

	componentIterator->first->setPosition(pos);
	pos.y += 175.0f; componentIterator++;
	componentIterator->first->setPosition(pos);
	pos.y += 250.0f; componentIterator++;
	componentIterator->first->setPosition(pos);
}


void SongsMenuState::createSongs()
{
	// Creates out songs composite
	mySongs = new SongGroup("All my Songs", "A song grouping containing all of my songs");
	I_SongComponent* industrialMusic = new SongGroup("Industrial", "is a style of experimental music that draws on transgressive and provocative themes");
	I_SongComponent* jazzMusic = new SongGroup("\nJazz", "is a music genre that originated at the beginning of the 20th Century, arguably earlier, within the African-American communities of the Southern United States.");
	I_SongComponent* dubstepMusic = new SongGroup("\nDubstep", "is a genre of electronic dance music that originated in South London, England");
		
	mySongs->accept(songAdder, industrialMusic);

	industrialMusic->accept(songAdder, new Song("Head Like a Hole", "NIN", 1990, string("Media/Songs/Song1.ogg")));
	industrialMusic->accept(songAdder, new Song("Headhunter", "Front 242", 1988, string("Media/Songs/Song1.ogg")));

	industrialMusic->accept(songAdder, dubstepMusic);
		
	dubstepMusic->accept(songAdder, new Song("Centipede", "Knife Party", 2012, string("Media/Songs/Song1.ogg")));
	dubstepMusic->accept(songAdder, new Song("Tetris", "Doctor P", 2011, string("Media/Songs/Song1.ogg")));
	
	mySongs->accept(songAdder, jazzMusic);
		
	jazzMusic->accept(songAdder, new Song("Alexander Where's That Band", "Paramount Recordings", 1970, string("Media/Songs/Alexander_Wheres_That_Band.ogg")));
	jazzMusic->accept(songAdder, new Song("Me and the Man in the Moon", "Ambassadors", 1980, string("Media/Songs/Ambassadors_Me_And_The_Man_In_The_Moon.ogg")));
	jazzMusic->accept(songAdder, new Song("Kater St. Rag", "Bennie Motens", 1980, string("Media/Songs/Bennie_Moten_Kater_St._Rag.ogg")));
	jazzMusic->accept(songAdder, new Song("South 1924", "Bennie Motens", 1980, string("Media/Songs/Bennie_Motens_KC_Jazz_Band-South_1924.ogg")));
	jazzMusic->accept(songAdder, new Song("When Eyes of Blue are foolin' You", "Howard Lanin", 1980, string("Media/Songs/Howard_Lanin_When_Eyes_Of_Blue_Are_Foolin__You.ogg")));

	createSongsAndBandsList(mySongs->getSongInfo(), "\t");
}


// Taken from stackoverflow and altered to suit
// http://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
void SongsMenuState::createSongsAndBandsList(string s, string delimiter)
{
	sf::Font f;
	f.loadFromFile("Media/Fonts/font1.ttf");
	int counter = 0;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		if(counter % 2 == 0)
		{
			//song name
			songsList.push_back(MenuComponentBuilder::getInstance()->createMenuComponentText(token,
																							 sf::Color::Green,
																							 sf::Color::White,
																							 f, 24,
																							 token));
		}else{
			//band name
			bandsList.push_back(MenuComponentBuilder::getInstance()->createMenuComponentText(token,
																							 sf::Color::Green,
																							 sf::Color::White,
																							 f, 24,
																							 token));
		}
		s.erase(0, pos + delimiter.length());
		counter++;
	}
}