#ifndef SONGSMENULEFTCOMMAND_H_
#define SONGSMENULEFTCOMMAND_H_

#include "Command.h"
#include "SongsMenuState.h"

class SongsMenuLeftCommand : public Command
{
public:
	SongsMenuLeftCommand(SongsMenuState* songsMenu){ this->songsMenu = songsMenu; }
	void execute(){ songsMenu->MenuUp(); } 

private:
	SongsMenuState* songsMenu;
};

#endif