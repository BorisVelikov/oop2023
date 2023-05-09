#include<iostream>
#include <string>
#include<vector>


class vehicle {
	std::string label;
	int people;
	double maxSpeed;
	int PPD;
public:
	int& getPPD() {
		return PPD;
	}
	virtual vehicle* copy() = 0;
};

class suv :public vehicle {
	bool gotin;
public:
	vehicle* copy() override {
		vehicle* temp = new suv(*this);
		return temp;
	}
};

class bus :public vehicle {
	int space;
public:
	vehicle* copy() override {
		vehicle* temp = new bus(*this);
		return temp;
	}
};

class car :public vehicle {
	std::string producer;
public:
	vehicle* copy() override {
		vehicle* temp = new car(*this);
		return temp;
	}
};

class Spark {
	std::vector<vehicle*> fleet;
public:
	void add(vehicle* src) {
		vehicle* temp = src->copy();
		fleet.push_back(temp);
	}
	int price(int i) {
		return fleet[i]->getPPD();
	}

};


int main() {

	return 0;
}