#include "state.h"

int main()
{
	TVRemoter<int> *remoter = new TVRemoter<int>();

	State<int> *start = new StartState<int>();
	remoter->changeState(start);
	cout << remoter->doAction(1) << endl;


	State<int> *processing = new ProcessingState<int>();
	remoter->changeState(processing);
	cout << remoter->doAction(2) << endl;

	State<int> *end = new EndState<int>();
	remoter->changeState(end);
	cout << remoter->doAction(3) << endl;

	return 0;
}
