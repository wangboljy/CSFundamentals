#ifndef COMMAND_H
#define COMMAND_H

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName &); \
	void operator=(const TypeName &) 

#include <list>
using std::list;

namespace cmd
{
// receiver is the real object which take the action.
class TV_receiver
{
private:
	DISALLOW_COPY_AND_ASSIGN(TV_receiver);
public:
	TV_receiver(){}
	void turn_on_tv();
	void turn_off_tv();
	void change_channel();
};

//Command is the wraper which call receiver to do the job. But using different interface
class Command
{
	public:
		virtual void execute() = 0;

		Command(TV_receiver * receiver):receiver(receiver) {};
	
	protected:
		TV_receiver *receiver;
};

class TurnOnCommand:public Command
{
	public:
		TurnOnCommand(TV_receiver *receiver):Command(receiver){};
		virtual void execute();
};

class TurnOffCommand:public Command
{
	public:
		TurnOffCommand(TV_receiver *receiver):Command(receiver){};
		virtual void execute();
};

class ChangeChannelCommand:public Command
{
	public:
		ChangeChannelCommand(TV_receiver *receiver);
		virtual void execute();
};

class Remoter
{
	public:
		Remoter(Command*,Command*,Command*);

		void turn_on();
		void turn_off();
		void change_channel();
	private:
		Command *turn_on_command;
		Command *turn_off_command;
		Command *change_channel_command;
};


// the macro command list is actually useful all the time
class MacroCommand:public Command
{
	public:
		MacroCommand(TV_receiver *);
		virtual void execute();
		void add_command(Command *);

	private:
		list<Command*> *commands;
};
};
#endif
