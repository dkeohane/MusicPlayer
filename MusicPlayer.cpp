#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(){}
MusicPlayer::~MusicPlayer(){}

void MusicPlayer::Start()
{
	this->Load();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
			// Update user input
			input->Update(event);
        }

		// Draw logic
		window.clear();
		this->currentState->Draw(window);
        window.display();
    }
}

void MusicPlayer::Update(I_Subject* theChangeSubject)
{
	if (theChangeSubject->getValue() != "Quit")
	{
		// Changes the menu state
		setCurrentState(availableStates[theChangeSubject->getValue()]);

		// Update the input commands to match the current menu state
		updateInputCommands(theChangeSubject->getValue());
	}else{
		//flush and close
		window.close();
	}
}

void MusicPlayer::Load()
{
	window.setFramerateLimit(60);
	window.create(sf::VideoMode(1280, 800), "My Music Player");
	window.setKeyRepeatEnabled(false);
	input = new Input();

	// Create States
	availableStates["MainMenu"]  = createState(std::string("MainMenu"));
	availableStates["SongsMenu"] = createState(std::string("SongsMenu"));

	// Attach Observer to newly created States
	availableStates["MainMenu"]->attach(this);
	availableStates["SongsMenu"]->attach(this);

	availableStates["SongsMenu"]->updateMenuEntryLocations(window);

	this->currentState = availableStates["MainMenu"];
	updateInputCommands(string("MainMenu"));
}

MenuState* MusicPlayer::createState(std::string& stateType)
{
	// Factory Method for creating new states
	if(stateType == "MainMenu")
	{
		return new MainMenuState();
	}
	else if(stateType == "SongsMenu")
	{
		return new SongsMenuState();
	}
}

void MusicPlayer::updateInputCommands(std::string& stateType)
{
	if(stateType == "MainMenu")
	{
		MainMenuState* m1 = (MainMenuState*)availableStates["MainMenu"];
		input->setCommandIndexed(new MainMenuSelectCommand(m1), Input::SELECT);
		input->setCommandIndexed(new MainMenuBackCommand(m1), Input::BACK);
		input->setCommandIndexed(new MainMenuUpCommand(m1), Input::UP);
		input->setCommandIndexed(new MainMenuDownCommand(m1), Input::DOWN);
		input->setCommandIndexed(new MainMenuLeftCommand(m1), Input::LEFT);
		input->setCommandIndexed(new MainMenuRightCommand(m1), Input::RIGHT);
	}
	else if(stateType == "SongsMenu")
	{
		SongsMenuState* m1 = (SongsMenuState*)availableStates["SongsMenu"];
		input->setCommandIndexed(new SongsMenuSelectCommand(m1), Input::SELECT);
		input->setCommandIndexed(new SongsMenuBackCommand(m1), Input::BACK);
		input->setCommandIndexed(new SongsMenuUpCommand(m1), Input::UP);
		input->setCommandIndexed(new SongsMenuDownCommand(m1), Input::DOWN);
		input->setCommandIndexed(new SongsMenuLeftCommand(m1), Input::LEFT);
		input->setCommandIndexed(new SongsMenuRightCommand(m1), Input::RIGHT);
	}
}