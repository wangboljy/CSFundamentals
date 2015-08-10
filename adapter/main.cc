#include "adapter.h"

int main()
{
	Adaptee * adaptee = new ConcreteAdaptee();
	Adapter *adapter = new Adapter(adaptee);
	adapter->show();
	return 0;
}
