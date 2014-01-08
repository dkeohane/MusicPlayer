#ifndef SONGSMENUUPCOMMAND_H_
#define SONGSMENUUPCOMMAND_H_

#include "Command.h"
#include "SongsMenuState.h"

class SongsMenuUpCommand : public Command
{
public:
	SongsMenuUpCommand(SongsMenuState* songsMenu){ this->songsMenu = songsMenu; }
	void execute(){ songsMenu->MenuUp(); } 

private:
	SongsMenuState* songsMenu;
};

#endif