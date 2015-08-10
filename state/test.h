#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;

class A
{
public:
	virtual void a()
	{
		cout << "a" << endl;
	}
};

class AA:public A
{
public:
	virtual void a()
	{
		cout << "aa" << endl;
	}
};

class Test
{
public:
	template<typename T>
	void sayT(const T &t)
	{
		cout << t << endl;
	}
	void show() 
	{
		cout << "show in pnt" << endl;
	}
};

class TT:public Test
{
public:
	template<typename T>
	void sayT(const T &t)
	{
		cout << "sayT in TT class " << endl;
		cout << t << endl;
	}
	void show() 
	{
		cout << "show in child" << endl;
	}
	/*
	template<typename T>
	T* sayTT(const T &t)
	{
		cout << "in TT class " << endl;
		cout << t << endl;
		return new T("=========asdf==========");
	}
	*/
};

template<typename T1, typename T2>
class Base
{
public:
	virtual void sayHi(const T1 &t1, const T2 &t2) = 0;
};

template<typename T1, typename T2>
class Derived: public Base<T1,T2>
{
public:
	virtual void sayHi(const T1 &t1, const T2 &t2) 
	{
		cout << t1 << endl;
		cout << t2 << endl;
	}
};
#endif
