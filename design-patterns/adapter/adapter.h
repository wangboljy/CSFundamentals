#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
using std::cout;
using std::endl;

class Target
{
	public:
		virtual void show() = 0;
};

class ConcreteTarget:public Target
{
	public:
		virtual void show()
		{
			cout << "concrete target show" << endl;
		}
};

class Adaptee
{
	public:
		virtual void sayHi() = 0;
};

class ConcreteAdaptee:public Adaptee
{
	public:
		virtual void sayHi()
		{
			cout << "adaptee say hi" << endl;
		}
};

class Adapter: public Target
{
	public:
		Adapter(Adaptee *a):adaptee(a) {};

		virtual void show()
		{
			adaptee->sayHi();
		}

	public:
		Adaptee *adaptee;
};
#endif
