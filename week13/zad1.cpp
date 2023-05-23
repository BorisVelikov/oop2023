#include"zad1.h"
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS

Car::Car(char* mod, char* o, bool t, int p, int w) :
	Property(o, t), Vehicle(p, w), model(new char[strlen(mod) + 1]) {
	strcpy(model, mod);
}

Car::~Car() {
	delete[] model;
}

Car::Car(const Car& other) : Property(other), Vehicle(other), model(new char[strlen(other.model) + 1]) {
	strcpy(model, other.model);
}

Car& Car::operator=(const Car& other) {
	if (this == &other)
		return *this;
	delete[] model;
	this->Vehicle::operator=(other);
	this->Property::operator=(other);
	model = new char[strlen(other.model) + 1];
	strcpy(model, other.model);
	
	return *this;
}

void Car::startEngine() {
	std::cout << "Vr";
	for (int i = 0; i < power; i++) {
		std::cout << "o";
	}
	std::cout << "m!\n";
}

void ElectricCar::startEngine() {
	std::cout << "(No Sound)";
}
