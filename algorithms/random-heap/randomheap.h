#ifndef RANDOM_HEAP
#define RANDOM_HEAP


template<class T>
struct TNode;

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  	TypeName(const TypeName &); \
	void operator=(const TypeName &)


#include <functional>
/**
 * Random heap definition.
 * User provide a comparator. Greater as default
 **/
template <class T, class Compare = std::greater<T> >
class RandomHeap {
  public:

	/**
	 * @constructor.
	 * User greater as default comparator
	 **/
	RandomHeap();

	/**
	 * @constructor.
	 **/
	RandomHeap(const Compare &);

	/**
	 * @deconstructor
	 **/
	~RandomHeap();

	/**
	 * Push an element into this heap
	 **/
	void push(T);

	/**
	 * check if heap is empty
	 **/
	bool empty() const;

	/**
	 * peek the top element
	 **/
	T top() const;

	/**
	 * Pop the top element
	 **/
	T pop();

  private:

	/**
	 * merge two TNode pointer
	 * @param TNode *p
	 * @param TNode *q
	 * @return TNode *
	 **/
	TNode<T> *merge(TNode<T> *p, TNode<T> *q);

	DISALLOW_COPY_AND_ASSIGN(RandomHeap);


  private:
	TNode<T> *root;
	Compare compare;
};

#include "randomheap.hpp"

#endif

