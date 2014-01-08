#ifndef INPUT_H_
#define INPUT_H_

#include "Global.h"
#include "Command.h"
#include "NoCommand.h"

class Input
{
public:
	Input();
	~Input();

	static const enum buttonCommad
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SELECT,
		BACK,
		_Count
	};

	void Update(sf::Event& event);
	void setUpCommand(Command* command){ commands.at(UP) = command; }
	void setDownCommand(Command* command){ commands.at(DOWN) = command; }
	void setLeftCommand(Command* command){ commands.at(LEFT) = command; }
	void setRightCommand(Command* command){ commands.at(RIGHT) = command; }
	void setSelectCommand(Command* command){ commands.at(SELECT) = command; }
	void setBackCommand(Command* command){ commands.at(BACK) = command; }
	void setAllCommand(Command* command);
	void setCommandIndexed(Command* command, int index);

private:
	std::vector<Command*> commands;
};

#endif