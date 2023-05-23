#include"jivotni.h"
#include<cstring>

int animal::count = 0;

int animal::eat()
{
	return weight;
}

int animal::getFood() const
{
	return lapanica;
}

animal::animal(const char* n_name, int w, food maaro) : weight(w), lapanica(maaro) {
	name = new char[strlen(n_name) + 1];
	strcpy(name, n_name);
	count++;
}

animal::animal(const animal& other) : lapanica(other.lapanica), weight(other.weight) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	count++;
}

animal& animal::operator=(const animal& other) {
	weight = other.weight;
	lapanica = other.lapanica;
	delete[] name;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	return *this;
}

mammal::mammal(const char* n_name, int w, food maaro, char* pesho) : animal(n_name, w, maaro) {
	osinovitel = new char[strlen(pesho) + 1];
	strcpy(osinovitel, pesho);
}

mammal::~mammal() {
	//delete[] name;
	delete[] osinovitel;
}

mammal::mammal(const mammal& other) : animal(other) {
	osinovitel = new char[strlen(other.osinovitel) + 1];
	strcpy(osinovitel, other.osinovitel);
}

mammal& mammal::operator=(const mammal& other) {
	this->animal::operator=(other);
	delete[] osinovitel;
	osinovitel = new char[strlen(other.osinovitel) + 1];
	strcpy(osinovitel, other.osinovitel);
	return *this;
}

bird::bird(const char* n_name, int w, food maaro, char* pesho, std::string grad) : 
	animal(n_name, w, maaro), city(grad){}
