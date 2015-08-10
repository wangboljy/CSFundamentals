#include "beverage.h"

int main()
{
	Beverage *moca = new MocaBeverage(20.5);
	Beverage *cobu = new CabuBeverage(15.3);

	moca = new MilkDecorator(1.2, moca);

	cobu = new FruitDecorator(3.2, cobu);
	cobu = new MilkDecorator(1.2, cobu);

	moca->cost();
	cout << "=========" << endl;
	cobu->cost();

	return 0;
}
