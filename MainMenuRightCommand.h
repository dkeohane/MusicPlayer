#ifndef MAINMENURIGHTCOMMAND_H_
#define MAINMENURIGHTCOMMAND_H_

#include "Command.h"
#include "MainMenuState.h"

class MainMenuRightCommand : public Command
{
public:
	MainMenuRightCommand(MainMenuState* mainMenu){ this->mainMenu = mainMenu; }
	void execute(){ this->mainMenu->MenuDown(); }

private:
	MainMenuState* mainMenu;
};

#endif