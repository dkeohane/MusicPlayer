#ifndef MAINMENUDOWNCOMMAND_H_
#define MAINMENUDOWNCOMMAND_H_

#include "Command.h"
#include "MainMenuState.h"

class MainMenuDownCommand : public Command
{
public:
	MainMenuDownCommand(MainMenuState* mainMenu){ this->mainMenu = mainMenu; }
	void execute(){ this->mainMenu->MenuDown(); }

private:
	MainMenuState* mainMenu;
};

#endif