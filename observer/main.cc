#include "observer.h"
#include "subject.h"


int main()
{
	Subject subject("lalala topic");
	Observer *a = new WBObserver("wb");
	Observer *b = new LJYObserver("ljy");

	subject.addObserver(a);
	subject.addObserver(b);

	subject.notify();


	subject.change("tttttttt");
	subject.remove(a);
	subject.notify();
	return 0;
}
