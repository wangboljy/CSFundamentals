#ifndef TREAP_HPP
#define TREAP_HPP

#include <cstdlib>

template <class T>
struct TNode {
  T data;
  long priority;
  struct TNode *left;
  struct TNode *right;
  struct TNode *pnt;

  TNode(const T &data):data(data), left(NULL), right(NULL), pnt(NULL) {
	// TODO: use seed
  	priority = rand() % 1000;
  }
};


template <class T, class Compare>
Treap<T, Compare>::Treap() {
  compare = Compare();
  this->root = NULL;
}

template <class T, class Compare>
Treap<T, Compare>::Treap(const Compare &compare) {
  this->root = NULL;
  this->compare = compare;
}

template <class T, class Compare>
Treap<T, Compare>::~Treap() {
  //TODO:
}

/**
 * search specified value from treap. Client should define '=='
 * @param: T data
 * @return: TNode<T> *
 **/
template <class T, class Compare>
const TNode<T>* Treap<T, Compare>::search(const T & value) {
  TNode<T> *ret = root;
  while(ret) {
	if(ret->data == value) 
	  break;
	if(value < ret->data ) 
	  ret = ret->left;
	else
	  ret = ret->right;
  }
  return ret;
}


/**
 * push an element into Treap. 
 * Insert it to the leaf node and then adjust it as a heap.
 **/
template <class T, class Compare>
void Treap<T, Compare>::push(T data) {
  TNode<T> *tmp = root;
  TNode<T> *pre = NULL;

  while(tmp) {
	pre = tmp;
	this->compare(tmp->data, data) ? tmp = tmp->left : tmp = tmp->right;
  }

  tmp = new TNode<T>(data);
  tmp->pnt = pre;

  if(!pre) 
	root = tmp;
  else {
	if(this->compare(pre->data, data))
	  pre->left = tmp;
	else
	  pre->right = tmp;
  }

  this->adjust(tmp);
}

/**
 * Adjust the heap by priority. For heap adjustment, we use max-heap as default.
 **/
template <class T, class Compare>
void Treap<T, Compare>::adjust(TNode<T> *node) {
  while(node != root) {
	TNode<T> *pre = node->pnt;

	if(pre->priority > node->priority)
	  break;
	// need adjust the heap nodes from this point
	if(pre->left == node)
	  right_rotate(node, pre);
	else
	  left_rotate(node, pre);
  }
}


/**
 * Left rotate child and pnt
 * @param c: child node
 * @param p: parent node
 **/
template <class T, class Compare>
void Treap<T, Compare>::left_rotate(TNode<T> *c, TNode<T> *p) {
  c->pnt = p->pnt;

  if(p->pnt)
	p->pnt->left == p ? p->pnt->left = c : p->pnt->right = c;

  p->pnt = c;
  p->right = c->left;
  if(c->left)
	c->left->pnt = p;
  c->left = p;

  if(c->pnt == NULL)
	root = c;
}

/**
 * Right rotate child and pnt
 * @param c: child node
 * @param p: parent node
 **/
template <class T, class Compare>
void Treap<T, Compare>::right_rotate(TNode<T> *c, TNode<T> *p) {
  c->pnt = p->pnt;

  if(p->pnt)
	p->pnt->left == p ? p->pnt->left = c : p->pnt->right = c;

  p->pnt = c;
  p->left = c->right;
  if(c->right)
	c->right->pnt = p;
  c->right = p;

  if(c->pnt == NULL) 
	root = c;
}

#endif
