#ifndef UNION_FIND
#define UNION_FIND

#ifdef UNION_FIND_DEBUG
#include <iostream>
using std::cout;
using std::endl;
#endif

class UnionFind {
	public:
		UnionFind(int maxn): maxn(maxn) {
			pnts = new int[maxn];
			for(int i = 0; i <	maxn; ++i) 
				pnts[i] = i;
		}

		~UnionFind() {
			delete pnts;
		}

		int find(int p) {
			int root = p;
			while(root != pnts[root])
				root = pnts[root];

			int tmp;
			while(p != root) {
				tmp = pnts[p];
				pnts[p] = root;
				p = tmp;
			}
			return root;
		}

		void merge(int x, int y) {
			int pntX = find(x);
			int pntY = find(y);
			pnts[pntX] = pntY;
		}

#ifdef UNION_FIND_DEBUG
		void show() {
			for(int i = 0; i < maxn; ++i) {
				cout << i << " parent is " << pnts[i] << endl;
			}
		}
#endif

	private:
		int maxn;
		int *pnts;
};

#endif
