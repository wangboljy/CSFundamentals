#include "duck.h"
#include "duck_factory.h"


int main() 
{

	Duck *duck = DuckFacotry::createDuck(RUB_DUCK);
	duck->show_info();
	duck->fly();
	duck->quake();

	duck = DuckFacotry::createDuck(NORMAL_DUCK);
	duck->show_info();
	duck->fly();
	duck->quake();

	delete duck;
	return 0;
}
