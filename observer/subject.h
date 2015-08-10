#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
using std::list;


class Observer;

struct Operator
{
	string sub;
	Operator(string sub):sub(sub){}
	void operator()(Observer* obv)
	{
		obv->update(sub);
	}
};

class Subject
{
	private:
		list<Observer*> *observers;

	private:
		void updateObserver(Observer *obv)
		{
			obv->update(subject);
		}
	public:
		Subject(const string& subject):subject(subject){
			observers = new list<Observer*>();
		}

		void addObserver(Observer* observer)
		{
			observers->push_back(observer);
		}

		void remove(Observer *observer)
		{
			observers->remove(observer);
		}

		void change(const string& subject)
		{
			this->subject =subject;
		}

		void notify()
		{
			//for_each(observers->begin(), observers->end(), Operator(subject));
			list<Observer*>::iterator it = observers->begin();
			while(it != observers->end()) {
				(*it)->update(subject);
				++it;
			}
		}

	private:
		string subject;
};


#endif
