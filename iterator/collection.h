#ifndef COLLECTION_H
#define COLLECTION_H

#include <vector>
using std::vector;

template<typename T>
class Iterator
{
	public:
		virtual bool hasNext() = 0;
		virtual T next() = 0;
};

template<typename T>
class CollectionIterator:public Iterator<T>
{
	public:
		CollectionIterator(vector<T> *v):v(v)
		{
			this->pos = 0;
			this->size = v->size();
		};

		virtual bool hasNext()
		{
			if(pos < size)
				return true;
			return false;
		}

		virtual T next()
		{
			return v->at(pos++);
		}

	private:
		vector<T> *v;
		int pos;
		int size;
};


template<typename T>
class Collection
{
	private:
		vector<T> v;

	public:
		
		void add(T t)
		{
			v.push_back(t);
		}

		Iterator<T>* createIterator()
		{
			return new CollectionIterator<T>(&v);
		}
};
#endif
