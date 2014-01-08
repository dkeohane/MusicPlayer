#ifndef MAINMENUUPCOMMAND_H_
#define MAINMENUUPCOMMAND_H_

#include "Command.h"
#include "MainMenuState.h"

class MainMenuUpCommand : public Command
{
public:
	MainMenuUpCommand(MainMenuState* mainMenu){ this->mainMenu = mainMenu; }
	void execute(){ this->mainMenu->MenuUp(); }

private:
	MainMenuState* mainMenu;
};

#endif