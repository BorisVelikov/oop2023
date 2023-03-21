#include"sklad.h"
#include<iostream>

Sklad::Sklad(int maxModels): models(new ShoeModel [maxModels]), cap(maxModels) {
}

Sklad::~Sklad() {
	delete[]models;
	models = nullptr;
}

Sklad::Sklad(Sklad const& other) : cap(other.cap), models(new ShoeModel[cap]) {
	for (int br = 0; br < cap; br++) {
		models[br] = other.models[br];
	}
}

Sklad& Sklad::operator=(Sklad const& other) {
	if (this != &other) {
		cap = other.cap;
		delete[]models;
		for (int br = 0; br < cap; br++) {
			models[br] = other.models[br];
		}
	}
	return *this;
}