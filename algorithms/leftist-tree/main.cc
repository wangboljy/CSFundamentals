#include "leftist-tree.h"
#include <iostream>
using std::cout;
using std::endl;

void testDefault() {
	LeftistTree<int> *l = new LeftistTree<int>();
	l->push(1);
	l->push(5);
	l->push(8);
	l->push(6);
	l->push(3);
	l->push(4);
	l->push(2);
	l->push(7);
	l->push(9);

	while(!l->empty()) {
		cout << l->top() <<  " ";
		l->pop();
	}
	cout << endl;
}

void testLess() {
	LeftistTree<int, std::less<int> > *s = new  LeftistTree<int, std::less<int> >();
	s->push(1);
	s->push(5);
	s->push(8);
	s->push(6);
	s->push(3);
	s->push(4);
	s->push(2);
	s->push(7);
	s->push(9);

	while(!s->empty()) {
		cout << s->top() <<  " ";
		s->pop();
	}
	cout << endl;
}

struct Func {
	bool operator()(int *a, int *b) {
		return *a > *b;
	}
};

void testPointer() {
	int a[] = {1,2,3,4,5,6,7,9,8,0};
	int len = sizeof(a)/sizeof(int);

	// both okay
	LeftistTree<int*, Func> *s = new LeftistTree<int*, Func>(Func());
	//LeftistTree<int*, Func> *s = new LeftistTree<int*, Func>();

	for(int i = 0; i < len; ++i) {
		s->push(a+i);
	}
	while(!s->empty()) {
		cout << *(s->top()) <<  " ";
		s->pop();
	}
	cout << endl;
}


int main() {
	testDefault();
	testLess();
	testPointer();
	return 0;
}
