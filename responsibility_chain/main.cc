#include "worker.h"

int main()
{

	Worker *emplyee = new Employee();
	Worker *manager = new Manager();
	emplyee->setNext(manager);

	emplyee->doWork();
	return 0;
}
