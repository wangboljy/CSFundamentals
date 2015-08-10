#ifndef CAR_BUILDER_H
#define CAR_BUILDER_H

#include <string>
#include <ostream>
using std::ostream;
using std::endl;
using std::string;

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName &); \
	void operator=(const TypeName &)

class Car
{
	private:
		DISALLOW_COPY_AND_ASSIGN(Car);
	public:
		string tire;
		string body;
		string engine;
		string brand;
	public:
		Car(){}
	
	friend ostream& operator<<(ostream& os, const Car& car);
};

ostream& operator<<(ostream& os, const Car& car)
{
	os << car.brand << endl;
	os << car.engine << endl;
	os << car.body << endl;
	os << car.tire << endl;
	return os;
}

class DIY_Car_builder:public Car
{
	public:
		 DIY_Car_builder* build_tire(string tire)
		{
			this->tire = tire;
			return this;
		}
		DIY_Car_builder* build_body(string body)
		{
			this->body = body;
			return this;
		}
		DIY_Car_builder* build_engine(string engine)
		{
			this->engine = engine;
			return this;
		}
		DIY_Car_builder* build_brand(string brand)
		{
			this->brand = brand;
			return this;
		}

		Car* build()
		{
			Car * car = new Car();
			car->tire = tire;
			car->body = body;
			car->engine = engine;
			car->brand = brand;
			return car;
		}

};

class Car_builder
{
	protected:
		virtual void build_tire() = 0;
		virtual void build_body() = 0;
		virtual void build_engine() = 0;
		virtual void build_brand() = 0;

	public:
		Car_builder()
		{
			car = new Car();
		}

		Car* build()
		{
			build_tire();
			build_body();
			build_engine();
			build_brand();
			return car;
		}

	protected:
		Car *car;
};

class bmw_car_builder: public Car_builder
{
	protected:
		virtual void build_tire()
		{
			car->tire = "bmw tire";
		}
		virtual void build_body()
		{
			car->body = "bmw body";
		}
		virtual void build_engine()
		{
			car->engine = "bmw engine";
		}
		virtual void build_brand()
		{
			car->brand = "bmw";
		}
};
#endif
