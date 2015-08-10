#ifndef WORKER_H
#define WORKER_H

#include <iostream>
using std::cout;
using std::endl;

class Worker
{
	private:
		Worker *next_worker;
	protected:
		virtual void work()=0;
	public:
		void doWork()
		{
			work();
			if(hasNext())
			{
				next()->work();
			}
		}
		bool hasNext()
		{
			if(next_worker != NULL)
				return true;
			return false;
		}
		Worker* next()
		{
			return next_worker;
		}

		void setNext(Worker *next)
		{
			next_worker = next;
		}
};

class Employee: public Worker
{
	protected:
		virtual void work()
		{
			cout << "Employee do work" << endl;
		}
};

class Manager: public Worker
{
	protected:
		virtual void work()
		{
			cout << "Manager do work" << endl;
		}
};
#endif
