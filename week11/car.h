#ifndef _CAR_H
#define _CAR_H
#include"carPart.h"
#include <string>

class Car {
	std::string producer;
	std::string model;
	CarPart** parts;
public:
	Car(std::string prod, std::string mod) : producer(prod), model(mod), parts(new CarPart*[10]){}

};



#endif // ! _CAR_H
