#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_

#include "Global.h"

#include "SongGroup.h"
#include "Song.h"
#include "MainMenuState.h"
#include "SongsMenuState.h"
#include "Input.h"

//Commands
#include "Commands.h"

#include "I_Observer.h"

class MusicPlayer : public I_Observer
{
public:
	MusicPlayer();
	MusicPlayer(I_State* state);
	~MusicPlayer();

	void Start();
	void Load();

	virtual void Update(I_Subject* theChangeSubject);
	void setCurrentState(I_State* state){ this->currentState = state; }
	MenuState* createState(std::string& stateType);
	void updateInputCommands(std::string& stateType);

private:
	I_State* currentState;
	std::map<std::string, MenuState*> availableStates;
	sf::RenderWindow window;
	Input* input;
};

#endif