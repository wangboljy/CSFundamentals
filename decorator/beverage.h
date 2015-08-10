#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
using std::cout;
using std::endl;

class Beverage
{
	protected:
		double price;

	public:
		Beverage(double price):price(price){}
		virtual void cost() = 0;
};

class MocaBeverage: public Beverage
{
	public:
		MocaBeverage(double price):Beverage(price){}

		virtual void cost()
		{
			cout << "Moca cost:" << price << endl;
		}
};

class CabuBeverage: public Beverage
{
	public:
		CabuBeverage(double price):Beverage(price) {}

		virtual void cost()
		{
			cout << "Cabu cost:" << price << endl;
		}
};

class Decorator:public Beverage
{
	public:
		Decorator(double price, Beverage *b):Beverage(price), beverage(b) {}

		virtual void cost() = 0;

	protected:
		Beverage *beverage;
};

class MilkDecorator: public Decorator
{
	public:
		MilkDecorator(double price, Beverage *b):Decorator(price, b){}

		virtual void cost() 
		{
			cout << "Milk cost: " << price << endl;
			beverage->cost();
		}
};

class FruitDecorator: public Decorator
{
	public:
		FruitDecorator(double price, Beverage *b):Decorator(price, b) {}

		virtual void cost()
		{
			cout << "Fruit cost: " << price << endl;
			beverage->cost();
		}
};
#endif
