#ifndef MEMENTO_H
#define MEMENTO_H

#include <ctime>
#include <list>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::list;

class Role;

class Memento
{
	public:
		Role *role;
		time_t saveTime;
	public:
		Memento(Role* role)
		{
			this->role = role;
			saveTime = time(&saveTime);
		}
		void show()
		{
			cout << "memento save time: " << ctime(&saveTime); 
		}
};

class Role
{
	protected:
		double blood;
		double mana;
		int level;
		string name;
	
	public:
		Role(double b, double m, int p,string n):blood(b), mana(m), level(p), name(n){}

		Memento* saveMemento()
		{
			return new Memento(this);
		}
		void restoreFromMemento(Memento *memento)
		{
			//the following will cause not polymofic
			*this = *(memento->role);
		}
		virtual void showStatus() 
		{
			cout << "-----------begin-------------" << endl;
			cout << "name: " << name << endl;
			cout << "blood: " << blood << endl;
			cout << "mana: " << mana << endl;
			cout << "level: " << level << endl;
			say();
			cout << "-----------end---------------" << endl;
		}
		virtual void say() = 0;
};

class CareTaker
{
	private:
		list<Memento*> mementos;
	public:
		Memento* getPreMemento()
		{
			Memento* m = mementos.back();
			mementos.pop_back();
			return m;
		}
		void saveMemento(Memento* m)
		{
			mementos.push_back(m);
		}
};

class Magician: public Role
{
	public:
		Magician(double b, double m, int p,string n):Role(b,m,p,n){}
		virtual void showStatus()
		{
			cout << "======= Magician status =======" << endl;
			Role::showStatus();
		}
		virtual void say()
		{
			cout << "Magician say hi" << endl;
		}
};

class Warrior: public Role
{
	public:
		Warrior(double b, double m, int p,string n):Role(b,m,p,n){}
		virtual void showStatus()
		{
			cout << "======= Warrior status =======" << endl;
			Role::showStatus();
		}
		virtual void say()
		{
			cout << "Warrior say hi" << endl;
		}
};
#endif
