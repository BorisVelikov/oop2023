#ifndef _VEHICLE_H
#define _VEHICLE_H
#include <string>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS

class Vehicle {
protected:
	int power;
	int weight;
public:
	int getPower() { return power; }
	int getWeight() { return weight; }
	virtual void startEngine() = 0;
	Vehicle(int p, int w) : power(p), weight(w){}
};

class Property {
protected:
	std::string owner;
	bool tangible;
public:
	bool isTangible() { return tangible; }
	std::string getOwner() { return owner; }
	Property(char* o, bool t):owner(o),tangible(t){}
};

class Car : public Property, public Vehicle {
protected:
	char* model;
public:
	Car(char* mod, char* o, bool t, int p, int w);
	~Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	void startEngine() override;
};

class ElectricCar : public Car {
public:
	void startEngine() override;
};




#endif