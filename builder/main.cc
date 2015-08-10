#include "car_builder.h"
#include <iostream>
using std::cout;


int main()
{
	Car_builder *builder = new bmw_car_builder();
	Car *car = builder->build();

	cout << *car << endl;


	DIY_Car_builder *diy = new DIY_Car_builder();
	car = diy->build_tire("diy tire")->build_body("diy body")->build_engine("diy engine")->build_brand("diy brand")->build();
	cout << *car << endl;
	return 0;
}
