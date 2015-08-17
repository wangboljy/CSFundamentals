#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP

#include <cstddef>
#include <functional>
#include <algorithm>

template <class T>
struct TNode {
	T data;
	int dist;
	struct TNode *left;
	struct TNode *right;

	TNode(const T &d):data(d), left(NULL), right(NULL), dist(0) {}
};


template <class T, class Compare>
LeftistTree<T, Compare>::LeftistTree() {
	this->root = NULL;
	this->compare = Compare();
}

template <class T, class Compare>
LeftistTree<T, Compare>::LeftistTree(const Compare &compare) {
	this->root = NULL;
	this->compare = compare;
}

template <class T, class Compare>
LeftistTree<T, Compare>::~LeftistTree() {
	while(!empty()) {
		TNode<T> *t = root;
		root = merge(root->left, root->right);
		delete t;
	}
}

template <class T, class Compare>
int LeftistTree<T, Compare>::getDist(TNode<T> *t) {
	return t ? t->dist : 0;
}

/**
* use dist to keep the tree balance. keep left tree greater than right tree.
* always insert node to right node. Once right tree is greater than left. swap them
**/
template <class T, class Compare>
TNode<T>* LeftistTree<T, Compare>::merge(TNode<T> *p, TNode<T> *q) {
	if(!p || !q)
		return p ? p : q;
	if(compare(p->data, q->data))
		std::swap(p, q);

	p->right = merge(p->right, q);

	int ld = getDist(p->left);
	int rd = getDist(p->right);
	if(rd > ld)
		std::swap(p->left, p->right);
	p->dist = getDist(p->right) + 1;

	return p;
}

template <class T, class Compare>
bool LeftistTree<T, Compare>::empty() const {
	return !root;
}

template <class T, class Compare>
void LeftistTree<T, Compare>::push(T t) {
	TNode<T> *n = new TNode<T>(t);
	root = merge(root, n);
}


template <class T, class Compare>
T LeftistTree<T, Compare>::top() const {
	return root->data;
}

template <class T, class Compare>
T LeftistTree<T, Compare>::pop() {
	TNode<T> *tmp = root;
	T ret = tmp->data;
	root = merge(root->left, root->right);
	delete tmp;
	return ret;
}

#endif
