#ifndef HEAP_H
#define HEAP_H

#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName &); \
	void operator=(const TypeName &)
#endif


#include <functional>
#include <vector>

template <class T, class Compare=std::greater<T> >
class Heap {
	public:
		Heap();

		Heap(const Compare&);

		template <class InputIterator>
		Heap(InputIterator first, InputIterator last);

		bool empty();

		void push(T);

		void pop();

		T top();

	private:
		void heapUp(int p);

		void heapDown(int p);

		DISALLOW_COPY_AND_ASSIGN(Heap);

	private:
		int heapsize;
		std::vector<T> heap;
		Compare compare;
};

#include "heap.hpp"

#endif
