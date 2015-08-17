#ifndef TREAP_H
#define TREAP_H

#ifdef TREAP_DEBUG
#include <iostream>
#include <queue>
#include <stack>
using std::cout;
using std::endl;
using std::queue;
using std::stack;
#endif


template <class T>
struct TNode;

#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName &); \
void operator=(const TypeName &)
#endif


#include <functional>

template <class T, class Compare = std::greater<T> >
class Treap {
  public:
	Treap(); 

	Treap(const Compare &);

	~Treap();

	/**
	 * push an element into Treap. 
	 * Insert it to the leaf node and then adjust it as a heap.
	 **/
	void push(T);

	/**
	 * search specified value from treap. Client should define '=='
	 * @param: T data
	 * @return: TNode<T> *
	 **/
	const TNode<T>* search(const T &);

  private:
	/**
	 * Adjust the heap by priority. For heap adjustment, we use max-heap as default.
	 **/
	void adjust(TNode<T> *);

	/**
	 * Left rotate child and pnt
	 * @param c: child node
	 * @param p: parent node
	 **/
	void left_rotate(TNode<T> *child, TNode<T> *parent);

	/**
	 * Right rotate child and pnt
	 * @param c: child node
	 * @param p: parent node
	 **/
	void right_rotate(TNode<T> *p, TNode<T> *q);

#ifdef TREAP_DEBUG
  public:
	void inDisp() {
	  if(!root)
		return;
	  stack<TNode<T> *> stk;
	  TNode<T> *tmp = root;
	  while(tmp || !stk.empty()) {
		while(tmp) {
		  stk.push(tmp);
		  tmp = tmp->left;
		}
		tmp = stk.top();
		cout << tmp->data << ", " << tmp->priority << endl;
		stk.pop();
		tmp = tmp->right;
	  }
	}

	void postDisp() {
	  if(!root)
		return;
	  stack<TNode<T> *> stk;
	  TNode<T> *tmp = root;
	  TNode<T> *pre = NULL;
	  while(tmp || !stk.empty()) {
		while(tmp) {
		  stk.push(tmp);
		  tmp = tmp->left;
		}
		tmp = stk.top();
		stk.pop();
		if(tmp->right == NULL || tmp->right == pre) {
		  cout << tmp->data << ", " << tmp->priority << endl;
		  pre = tmp;
		  tmp = NULL;
		} else {
		  stk.push(tmp);
		  tmp = tmp->right;
		}
	  }
	}

	void levelDisp() {
	  if(!root)
		return;
	  queue<TNode<T> *> que;
	  que.push(root);
	  while(!que.empty()) {
		TNode<T> *tmp = que.front();
		que.pop();
		cout << tmp->data << ", " << tmp->priority << endl;
		tmp->left ? que.push(tmp->left) : void(0);
		tmp->right ? que.push(tmp->right) : void(0);
	  }
	}
#endif


  private:
	TNode<T> *root;
	Compare compare;
};

#include "treap.hpp"
#endif
