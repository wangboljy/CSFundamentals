#ifndef RANDOM_HEAP_HPP
#define RANDOM_HEAP_HPP

#include <cstddef>

template<typename T>
struct TNode {
	T data;
	struct TNode *left;
	struct TNode *right;

	TNode(T d): data(d), left(NULL), right(NULL) {}
};



#include <functional>
#include <algorithm>

/**
 * @constructor
 **/
template <typename T, class Compare>
RandomHeap<T, Compare>::RandomHeap() {
	this->root = NULL;
	this->compare = std::greater<int>();
}

/**
 * @constructor
 **/
template <typename T, class Compare>
RandomHeap<T, Compare>::RandomHeap(const Compare &compare) {
	this->root = NULL;
	this->compare = compare;
}

/**
 * @deconstructor
 **/
template <typename T, class Compare>
RandomHeap<T, Compare>::~RandomHeap() {
	while(!empty()) {
		TNode<T> *t = root;
		root = merge(root->left, root->right);
		delete t;
	}
}

/**
 * merge two TNode pointer
 * @param TNode *p
 * @param TNode *q
 * @return TNode *
 **/
template <typename T, class Compare>
TNode<T>* RandomHeap<T, Compare>::merge(TNode<T> *p, TNode<T> *q) {
	if(!p || !q)
		return p ? p : q;

	if(compare(p->data, q->data)) 
		std::swap(p, q);

	if(rand() % 2)
		p->left = merge(p->left, q);
	else
		p->right = merge(p->right, q);

	return p;
}


template <typename T, class Compare>
void RandomHeap<T, Compare>::push(T t) {
	TNode<T> *n = new TNode<T>(t);
	root = merge(root, n);
}

template <typename T, class Compare>
bool RandomHeap<T, Compare>::empty() const {
	return root == NULL;
}

template <typename T, class Compare>
T RandomHeap<T, Compare>::top() const {
	return root->data;
}

template <typename T, class Compare>
T RandomHeap<T, Compare>::pop() {
	TNode<T>* tmp = root;
	root = this->merge(root->left, root->right);
	T ret = tmp->data;
	delete tmp;
	return ret;
}

#endif
