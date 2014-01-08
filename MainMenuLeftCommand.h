#ifndef MAINMENULEFTCOMMAND_H_
#define MAINMENULEFTCOMMAND_H_

#include "Command.h"
#include "MainMenuState.h"

class MainMenuLeftCommand : public Command
{
public:
	MainMenuLeftCommand(MainMenuState* mainMenu){ this->mainMenu = mainMenu; }
	void execute(){ this->mainMenu->MenuUp(); }

private:
	MainMenuState* mainMenu;
};

#endif