#ifndef Duck_FACTORY_H
#define Duck_FACTORY_H

#include "duck.h"

enum Duck_Type
{
	RUB_DUCK,
	NORMAL_DUCK
};
class DuckFacotry
{
	public:
		static FlyBehaviro *rocket;
		static FlyBehaviro *wing;
		static QuakeBehaviro *noQuake;
		static QuakeBehaviro *normal;
	public:
		static Duck* createDuck(Duck_Type type)
		{
			Duck *duck = NULL;
			switch(type)
			{
				case RUB_DUCK:
					duck = new Rub_Duck(20.3, "red", rocket, noQuake);
					break;
				case NORMAL_DUCK:
					duck = new Normal_Duck(50.5, "white", wing, normal);
					break;
				default:
					duck = NULL;
			}
			return duck;
		}
};

FlyBehaviro* DuckFacotry::rocket = new FlyBehavior_with_rocket();
FlyBehaviro* DuckFacotry::wing = new FlyBehaviro_with_wing();
QuakeBehaviro* DuckFacotry::noQuake = new QuakeBehaviro_NoQuake();
QuakeBehaviro* DuckFacotry::normal = new QuakeBehaviro_Normal();

#endif
