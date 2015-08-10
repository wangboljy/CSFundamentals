#ifndef STATE_H
#define STATE_H

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;


template<typename T>
class State
{
	public:
		virtual string doAction(const T &input)=0;
};

template<typename T>
class StartState:public State<T>
{
	public:
		virtual string doAction(const T &input)
		{
			cout << input << endl;
			return "start state action done";
		}
};

template<typename T>
class ProcessingState:public State<T>
{
	public:
		virtual string doAction(const T &input)
		{
			cout << input << endl;
			return  string("processing state action done");
		}
};

template<typename T>
class EndState:public State<T>
{
	public:
		virtual string doAction(const T &input)
		{
			cout << input << endl;
			return string("end state action done");
		}
};


template<typename T>
class TVRemoter
{
	private:
		State<T> *state;
	public:
		void changeState(State<T> *state)
		{
			this->state = state;
		}

		string doAction(const T &input)
		{
			return state->doAction(input);
		}
};
#endif
