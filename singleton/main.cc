#include "singleton.h"


int main() 
{
	Checker *checker = Checker::getInstance();
	checker->sayHi();

	checker = Checker::getInstance();
	checker->sayHi();


	Validator *validator = Validator::getInstance();
	validator->sayHi();

	validator = Validator::getInstance();
	validator->sayHi();


	staticTest *staticTest = staticTest::getInstance();
	staticTest->sayHi();

	staticTest = staticTest::getInstance();
	staticTest->sayHi();
	return 0;
}
