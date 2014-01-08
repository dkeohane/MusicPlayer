#ifndef MAINMENUSELECTCOMMAND_H_
#define MAINMENUSELECTCOMMAND_H_

#include "Command.h"
#include "MainMenuState.h"

class MainMenuSelectCommand : public Command
{
public:
	MainMenuSelectCommand(MainMenuState* mainMenu){ this->mainMenu = mainMenu; }
	void execute(){ this->mainMenu->MakeSelection(); }

private:
	MainMenuState* mainMenu;
};

#endif