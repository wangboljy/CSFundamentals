#include "heap.h"
#include <iostream>
using namespace std;

void testDefault() {
	Heap<int> heap;
	heap.push(7);
	heap.push(4);
	heap.push(2);
	heap.push(8);
	heap.push(3);
	heap.push(1);
	heap.push(9);
	heap.push(5);
	heap.push(0);
	heap.push(6);

	while(!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;
}

void testLess() {
	Heap<int, std::less<int> > heap;

	heap.push(7);
	heap.push(4);
	heap.push(2);
	heap.push(8);
	heap.push(3);
	heap.push(1);
	heap.push(9);
	heap.push(5);
	heap.push(0);
	heap.push(6);

	while(!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;
}

void testIter() {
	int a[] = {7,4,2,8,3,1,9,5,0,6};
	Heap<int> heap(a, a+sizeof(a)/sizeof(int));
	
	while(!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
	cout << endl;
}

struct Func{
	bool operator()(int *a, int *b) {
		return *a < *b;
	}
};

void testFunc() {
	int a[] = {7,4,2,8,3,1,9,5,0,6};
	Heap<int*, Func> heap;
	int len = sizeof(a)/sizeof(int);
	for(int i = 0; i < len; ++i) 
		heap.push(a+i);

	while(!heap.empty()){
		cout << *heap.top() << " ";
		heap.pop();
	}
	cout << endl;
}

int main() {
	testDefault();
	testLess();
	testIter();
	testFunc();
	return 0;
}
