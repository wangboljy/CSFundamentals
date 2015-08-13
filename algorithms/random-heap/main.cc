#include "randomheap.h"

#include <iostream>
using namespace std;

void testDefault() {
	RandomHeap<int> randomHeap;
	randomHeap.push(1);
	randomHeap.push(5);
	randomHeap.push(8);
	randomHeap.push(6);
	randomHeap.push(3);
	randomHeap.push(4);
	randomHeap.push(2);
	randomHeap.push(7);
	randomHeap.push(9);

	while(!randomHeap.empty()) {
		cout << randomHeap.top() <<  " ";
		randomHeap.pop();
	}
	cout << endl;
}

void testLess() {
	RandomHeap<int, std::less<int> > *s = new  RandomHeap<int, std::less<int> >(std::less<int>() );
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
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int len = sizeof(a)/sizeof(int);

	RandomHeap<int*, Func> *s = new RandomHeap<int*, Func>(Func());

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
