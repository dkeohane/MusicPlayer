#ifndef MAINMENUBACKCOMMAND_H_
#define MAINMENUBACKCOMMAND_H_

#include "Command.h"
#include "MainMenuState.h"

class MainMenuBackCommand : public Command
{
public:
	MainMenuBackCommand(MainMenuState* mainMenu){ this->mainMenu = mainMenu; }
	void execute(){ mainMenu->Back(); } 

private:
	MainMenuState* mainMenu;
};

#endif