#define UNION_FIND_DEBUG UNION_FIND_DEBUG

#include "unionfind.h"


int main() {
	UnionFind uf(10);

	uf.merge(2,3);
	uf.merge(4,5);
	uf.merge(6,7);
	uf.merge(7,4);

	uf.show();
	cout << "---------------" << endl;

	uf.find(4);
	uf.show();
	cout << "---------------" << endl;
	uf.find(6);
	uf.show();
	cout << "---------------" << endl;
	uf.merge(6,3);
	uf.show();

	return 0;
}
