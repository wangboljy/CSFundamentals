#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <string>
#include <iostream>
#include <ostream>
using std::string;
using std::cout;
using std::endl;
using std::ostream;


#define DIS_ALLOW_ASSIGN_AND_COPY(typeName) \
	typeName(const typeName&); \
	void operator=(const typeName&)

class Robot
{
	public:
		string model;
		int height;

	public:
		Robot(string m, int h):model(m),height(h) {}

		Robot* clone()
		{
			return new Robot(this->model, this->height);
		}


		friend ostream& operator<<(ostream& os, const Robot *r);
};

ostream& operator<<(ostream& os, const Robot *r)
{
	os << r->model << endl;
	os << r->height << endl;
}


#endif
