#include "Input.h"

Input::Input()
{
	setAllCommand(new NoCommand());
}

Input::~Input()
{
	commands.erase(commands.begin(), commands.end());
}

void Input::Update(sf::Event& event)
{
	if(event.type == sf::Event::KeyReleased)
	{
		// Up
		if(event.key.code == sf::Keyboard::Up)
		{
			commands.at(UP)->execute();
		}
		// Down
		else if(event.key.code == sf::Keyboard::Down)
		{
			commands.at(DOWN)->execute();
		}
		// Left
		else if(event.key.code == sf::Keyboard::Left)
		{
			commands.at(LEFT)->execute();
		}
		// Right
		else if(event.key.code == sf::Keyboard::Right)
		{
			commands.at(RIGHT)->execute();
		}
		// Select
		else if(event.key.code == sf::Keyboard::Return)
		{
			commands.at(SELECT)->execute();
		}
		// Back
		else if(event.key.code == sf::Keyboard::BackSpace)
		{
			commands.at(BACK)->execute();
		}
	}
}

void Input::setAllCommand(Command* command)
{
	this->commands.assign(Input::_Count, command);
}

void Input::setCommandIndexed(Command* command, int index)
{
	if(index < _Count)
	{
		commands.at(index) = command;
	}
	else
	{
		cout << "Cannot add Command to invalid index (" << index << ")" << endl;
	}
}