#include "test.h"
#include <string>
using std::string;

int main()
{

	A *a = new A();
	a->a();
	A *aa = new AA();
	aa->a();

	Test *t = new Test();
	t->sayT(13);
	t->sayT("wangboo");
	t->show();

	Test *tt = new TT();
	tt->sayT(20);
	tt->sayT("some string test");
	tt->show();
	//cout << *tt->sayTT(string("some string test")) << endl;

	Base<int, string> *b = new Derived<int, string>();
	b->sayHi(345, "ljy");
	return 0;
}
