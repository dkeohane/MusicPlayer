#ifndef SONGSMENURIGHTCOMMAND_H_
#define SONGSMENURIGHTCOMMAND_H_

#include "Command.h"
#include "SongsMenuState.h"

class SongsMenuRightCommand : public Command
{
public:
	SongsMenuRightCommand(SongsMenuState* songsMenu){ this->songsMenu = songsMenu; }
	void execute(){ this->songsMenu->MenuDown(); }

private:
	SongsMenuState* songsMenu;
};

#endif