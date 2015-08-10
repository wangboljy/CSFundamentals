#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include <iostream>
using std::cout;
using std::endl;

class Product
{
	public:
		virtual void show() = 0;
};

class ConcreteProduct:public Product
{
	public:
		virtual void show()
		{
			cout << "this is concrete product" << endl;
		}
};

class FactoryMethod
{
	public:
		void factoryMethod()
		{
			Product *p = makeProduct();
			p->show();
		}
	protected:
		virtual Product* makeProduct() = 0;
};

class ConcreteFactoryMethod:public FactoryMethod
{
	protected:
		virtual Product* makeProduct()
		{
			return new ConcreteProduct();
		}
};
#endif
