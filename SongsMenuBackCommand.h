#ifndef SONGSMENUBACKCOMMAND_H_
#define SONGSMENUBACKCOMMAND_H_

#include "Command.h"
#include "SongsMenuState.h"

class SongsMenuBackCommand : public Command
{
public:
	SongsMenuBackCommand(SongsMenuState* songsMenu){ this->songsMenu = songsMenu; }
	void execute(){ songsMenu->Back(); } 

private:
	SongsMenuState* songsMenu;
};

#endif