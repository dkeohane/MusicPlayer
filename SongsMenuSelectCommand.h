#ifndef SONGSMENUSELECTCOMMAND_H_
#define SONGSMENUSELECTCOMMAND_H_

#include "Command.h"
#include "SongsMenuState.h"

class SongsMenuSelectCommand : public Command
{
public:
	SongsMenuSelectCommand(SongsMenuState* songsMenu){ this->songsMenu = songsMenu; }
	void execute(){ this->songsMenu->MakeSelection(); }

private:
	SongsMenuState* songsMenu;
};

#endif