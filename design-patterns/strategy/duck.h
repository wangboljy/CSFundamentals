#ifndef DUCK_H
#define DUCK_H

#include <string>
#include "behavior.h"
using std::string;

class Duck
{
	public:
		double weight;
		string color;
		FlyBehaviro *fly_behaviro;
		QuakeBehaviro *quake_behaviro;

	public:
		Duck(double weight, string color, FlyBehaviro *fly_behaviro, QuakeBehaviro *quake_behaviro)
		{
			this->weight = weight;
			this->color = color;
			this->fly_behaviro = fly_behaviro;
			this->quake_behaviro = quake_behaviro;
		}

		virtual void fly() 
		{
			fly_behaviro->fly();
		}

		virtual void quake() 
		{
			quake_behaviro->quake();
		}

		virtual void show_info() 
		{
			cout << "color: " << this->color << endl;
			cout << "weight: " << this->weight << endl;
		}
};


class Rub_Duck: public Duck
{
	public:
		Rub_Duck(double weight, string color, FlyBehaviro *fly_behaviro, QuakeBehaviro *quake_behaviro): Duck(weight, color, fly_behaviro, quake_behaviro) {}

		virtual void show_info() 
		{
			cout << "this is rub duck" << endl;
			this->Duck::show_info();
		}
};

class Normal_Duck: public Duck
{
	public:
		Normal_Duck(double weight, string color, FlyBehaviro *fly_behaviro, QuakeBehaviro *quake_behaviro): Duck(weight, color, fly_behaviro, quake_behaviro) {}

		virtual void show_info() 
		{
			cout << "this is normal Duck" << endl;
			this->Duck::show_info();
		}
};

#endif

