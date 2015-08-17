
#define TREAP_DEBUG debug 

#include "treap.h"
#include <cassert>

void testDefault() {
	Treap<int> treap;
	treap.push(1);
	treap.push(5);
	treap.push(8);
	treap.push(6);
	treap.push(3);
	treap.push(4);
	treap.push(2);
	treap.push(7);
	treap.push(9);

	treap.inDisp();
	cout << "--------------------" << endl;
	treap.postDisp();
	cout << "--------------------" << endl;
	treap.levelDisp();

	const TNode<int> *ret = treap.search(3);
	assert(ret->data == 3);

	ret = treap.search(17);
	assert(ret == NULL);

}

void testLess() {
	Treap<int, std::less<int> > *treap = new Treap<int, std::less<int> >();
	treap->push(1);
	treap->push(5);
	treap->push(8);
	treap->push(6);
	treap->push(3);
	treap->push(4);
	treap->push(2);
	treap->push(7);
	treap->push(9);

	treap->inDisp();
	cout << "--------------------" << endl;
	treap->postDisp();
	cout << "--------------------" << endl;
	treap->levelDisp();

	const TNode<int> *ret = treap->search(3);
	assert(ret->data == 3);

	ret = treap->search(17);
	assert(ret == NULL);
}

int main() {
	//testDefault();
	testLess();
	return 0;
}
