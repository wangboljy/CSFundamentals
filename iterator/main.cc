#include "collection.h"
#include <iostream>
using std::cout;
using std::endl;


int main()
{
	Collection<int> *collection = new Collection<int>();
	collection->add(1);
	collection->add(2);
	collection->add(3);
	collection->add(4);
	collection->add(5);
	collection->add(6);
	collection->add(7);
	collection->add(8);
	Iterator<int> *iterator = collection->createIterator();

	while(iterator->hasNext())
	{
		int x = iterator->next();
		cout << x << endl;
	}
	return 0;
}
