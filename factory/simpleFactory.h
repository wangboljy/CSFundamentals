#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include <string>
using std::string;

enum SEX
{
	MAN, WOMEN
};

class Person
{
	public:
		string sex;
	public:
		Person(string sex):sex(sex){}
};

#define DISALLOW_COPY_AND_ASSIGN(Typename) \
	Typename(const Typename &); \
	void operator=(const Typename &)

class PersonFactory
{
	private:
		PersonFactory(){}
		DISALLOW_COPY_AND_ASSIGN(PersonFactory);

	public:
		static Person* getPerson(SEX sex)
		{
			Person *p = NULL;
			switch(sex)
			{
				case MAN:
					p = new Person("man"); break;
				case WOMEN:
					p = new Person("woman"); break;
				default:
					break;
			}
			return p;
		}
};
#endif
