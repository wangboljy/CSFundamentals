#ifndef BEHAVIRO_H
#define BEHAVIRO_H

#include <iostream>

using std::cout;
using std::endl;

class FlyBehaviro
{
	public:
		virtual void fly() = 0;
};

class FlyBehavior_with_rocket:public FlyBehaviro
{
	public:
		virtual void fly()
		{
			cout << "fly with rocket" <<endl;
		}
};

class FlyBehaviro_with_wing:public FlyBehaviro
{
	public:
		virtual void fly() 
		{
			cout << "fly with wing" << endl;
		}
};


class QuakeBehaviro
{
	public:
		virtual void quake() = 0;
};

class QuakeBehaviro_Normal: public QuakeBehaviro
{
	public:
		virtual void quake() 
		{
			cout << "just normal quake" << endl;
		}
};

class QuakeBehaviro_NoQuake:public QuakeBehaviro
{
	public:
		virtual void quake() 
		{
			cout << "can't quake" << endl;
		}
};
#endif
