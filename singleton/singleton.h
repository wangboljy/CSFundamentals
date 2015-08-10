#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
using std::cout;
using std::endl;

#include <pthread.h>


#define DISALLOW_COPY_AND_ASSIGN(Typename) \
	Typename(const Typename &); \
	void operator=(const Typename&)

class Checker
{
	private:
		Checker() {}
		DISALLOW_COPY_AND_ASSIGN(Checker);

	public:
		static Checker* getInstance() 
		{
			if(checker == NULL)
			{
				pthread_mutex_lock(&mutex);
				if(checker == NULL)
				{
					checker = new Checker();
				}
				pthread_mutex_unlock(&mutex);
			}
			return checker;
		}

		void sayHi()
		{
			cout << this << endl;
		}

	private:
		static pthread_mutex_t mutex;
		static Checker *checker;
};

Checker* Checker::checker = NULL;
pthread_mutex_t Checker::mutex = PTHREAD_MUTEX_INITIALIZER;

//==================

class Validator
{
	private:
		Validator(){};
		DISALLOW_COPY_AND_ASSIGN(Validator);

	public:
		static Validator* getInstance()
		{
			static Validator *validator = new Validator();
			return validator;
		}

		void sayHi()
		{
			cout << this << endl;
		}
};

//=========================
class staticTest
{
	private:
		staticTest() {};
		DISALLOW_COPY_AND_ASSIGN(staticTest);

	public:
		static staticTest* getInstance()
		{
			return instance;
		}

		void sayHi()
		{
			cout << this << endl;
		}

	private:
		static staticTest* instance;
};

staticTest* staticTest::instance = new staticTest::staticTest();
#endif
