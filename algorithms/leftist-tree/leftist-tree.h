#ifndef LEFTIST_TREE_H
#define LEFTIST_TREE_H

#include <cstddef>

template <class T>
struct TNode; 

#ifndef DISALLOW_COPY_AND_ASSIGN
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName &); \
	void operator=(const TypeName &)
#endif



#include <functional>

template <class T, class Compare = std::greater<int> >
class LeftistTree {
	public:
		/**
		* @constructor
		**/
		LeftistTree();

		/**
		* @constructor
		**/
		explicit LeftistTree(const Compare &compare);

		/**
		* @deconstructor
		**/
		~LeftistTree();

		/**
		* check if heap is empty
		**/
		bool empty() const;

		/**
		* push an element into heap
		**/
		void push(T);

		/**
		* pop out the top element
		**/
		T pop();

		/**
		* peek the top element
		**/
		T top() const;

	private:
		/**
		* use dist to keep the tree balance. keep left tree greater than right tree.
		* always insert node to right node. Once right tree is greater than left. swap them
		**/
		TNode<T> *merge(TNode<T> *, TNode<T> *);

		/**
		* get tree distance to leaf
		**/
		int getDist(TNode<T> *);

		DISALLOW_COPY_AND_ASSIGN(LeftistTree);

	private:
		TNode<T> *root;
		Compare compare;
};

#include "leftist-tree.hpp"

#endif
