#include "simpleFactory.h"
#include "factoryMethod.h"
#include <iostream>
using std::cout;
using std::endl;


int main()
{
	Person *p = PersonFactory::getPerson(MAN);
	cout << p->sex << endl;

	p = PersonFactory::getPerson(WOMEN);
	cout << p->sex << endl;


	FactoryMethod *f = new ConcreteFactoryMethod();
	f->factoryMethod();

	return 0;
}
