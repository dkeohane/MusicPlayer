#ifndef SONGSMENUDOWNCOMMAND_H_
#define SONGSMENUDOWNCOMMAND_H_

#include "Command.h"
#include "SongsMenuState.h"

class SongsMenuDownCommand : public Command
{
public:
	SongsMenuDownCommand(SongsMenuState* songsMenu){ this->songsMenu = songsMenu; }
	void execute(){ songsMenu->MenuDown(); } 

private:
	SongsMenuState* songsMenu;
};

#endif