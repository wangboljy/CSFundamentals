#include "prototype.h"



int main()
{
	Robot *r = new Robot("new stype", 185);
	cout << r ;

	Robot *x = r->clone();
	cout << x;
	return 0;
}
