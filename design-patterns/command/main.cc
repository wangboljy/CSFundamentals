#include "command.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace cmd;

int main()
{
	TV_receiver *receiver = new TV_receiver();

	Command *turn_on_command = new TurnOnCommand(receiver);
	Command *turn_off_command = new TurnOffCommand(receiver);
	Command *change_channel_command = new ChangeChannelCommand(receiver);

	Remoter *remoter = new Remoter(turn_on_command, turn_off_command, change_channel_command);

	remoter->turn_on();
	remoter->change_channel();
	remoter->turn_off();


	cout << "==========below is macro command lists example=========" << endl;

	MacroCommand *macro = new MacroCommand(receiver);
	macro->add_command(turn_on_command);
	macro->add_command(change_channel_command);
	macro->add_command(change_channel_command);
	macro->add_command(change_channel_command);
	macro->add_command(change_channel_command);
	macro->add_command(turn_off_command);
	macro->execute();
	return 0;
}
