#include "command.h"
#include <iostream>
using std::cout;
using std::endl;

namespace cmd
{

void TV_receiver::turn_on_tv()
{
	cout << ">>> turn on tv..." << endl;
}
void TV_receiver::turn_off_tv()
{
	cout << ">>> turn off tv..." << endl;
}
void TV_receiver::change_channel()
{
	cout << ">>> change channel..." << endl;
}

void TurnOnCommand::execute()
{
	receiver->turn_on_tv();
}
void TurnOffCommand::execute()
{
	receiver->turn_off_tv();
}
ChangeChannelCommand::ChangeChannelCommand(TV_receiver *receiver):Command(receiver){}
void ChangeChannelCommand::execute()
{
	receiver->change_channel();
}

Remoter::Remoter(Command* turnon, Command *turnoff, Command *change):turn_on_command(turnon),turn_off_command(turnoff), change_channel_command(change)
{}

void Remoter::turn_on()
{
	this->turn_on_command->execute();
}
void Remoter::turn_off()
{
	this->turn_off_command->execute();
}
void Remoter::change_channel()
{
	this->change_channel_command->execute();
}

// macro batch commands, actually this is the useful part
MacroCommand::MacroCommand(TV_receiver *receiver):Command(receiver)
{
	this->commands = new list<Command*>();
}
void MacroCommand::add_command(Command *c)
{
	this->commands->push_back(c);
}
void MacroCommand::execute()
{
	for(list<Command*>::iterator it=commands->begin(); it != commands->end(); ++it)
	{
		(*it)->execute();
	}
}
};
