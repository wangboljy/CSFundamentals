#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
using namespace std;


class Observer
{
	private:
		string observerName;

	public:
		Observer(string name): observerName(name){}

		void update(const string &subject) 
		{
			cout <<"observer: " << observerName << " get new subject: " << subject << endl;
		}
};

class WBObserver:public Observer
{
	public:
		WBObserver(const string& name):Observer(name){}
};
class LJYObserver:public Observer
{
	public:
		LJYObserver(const string& name):Observer(name){}
};
#endif 
