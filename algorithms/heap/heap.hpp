#ifndef HEAP_HPP
#define HEAP_HPP

#include <algorithm>


template <class T, class Compare>
Heap<T, Compare>::Heap() {
	this->compare = Compare();
	heapsize = 0;
}

template <class T, class Compare>
Heap<T, Compare>::Heap(const Compare &compare) {
	this->compare = compare;
	heapsize = 0;
}

template <class T, class Compare>
template <class InputIterator>
Heap<T, Compare>::Heap(InputIterator first, InputIterator last) {
	heapsize = 0;
	if(first != last)
		heap.push_back(*first);
	for(; first != last; ++first) {
		heap.push_back(*first);
		++heapsize;
		heapUp(heapsize);
	}
}


template <class T, class Compare>
void Heap<T, Compare>::heapUp(int p) {
	int q = p >> 1;
	T tmp = heap[p];
	while(q) {
		if(compare(tmp, heap[q])) 
			heap[p] = heap[q];
		else
			break;
		p = q;
		q = p >> 1;
	}
	heap[p] = tmp;
}

template <class T, class Compare>
void Heap<T, Compare>::heapDown(int p) {
	int q = p << 1;
	T tmp = heap[p];
	while(q <= heapsize) {
		if(q < heapsize && compare(heap[q+1], heap[q]))
			++q;
		if(compare(heap[q], tmp))
			heap[p] = heap[q];
		else
			break;
		p = q;
		q = p << 1;
	}
	heap[p] = tmp;
}


template <class T, class Compare>
bool Heap<T, Compare>::empty() {
	return heapsize <= 0;
}

template <class T, class Compare>
void Heap<T, Compare>::push(T t) {
	heap.push_back(t);
	// sentinel 
	if(heapsize == 0) 
		heap.push_back(t);
	++heapsize;
		
	heapUp(heapsize);
}

template <class T, class Compare>
void Heap<T, Compare>::pop() {
	if(empty())
		return;
	std::swap(heap[1], heap[heapsize--]);
	heapDown(1);
}

template <class T, class Compare>
T Heap<T, Compare>::top() {
	return heap[1];
}

#endif
