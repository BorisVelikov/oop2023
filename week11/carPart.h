#ifndef _ZELE_H
#define _ZELE_H
#include <string>
#include<vector>
#include<iostream>

class CarPart {
protected:
	std::string name;
	std::string producer;
	unsigned year;
	int serialNumber;
public:
	CarPart(std::string n_name, std::string n_producer, unsigned n_year) : 
		name(n_name), producer(n_producer), year(n_year), serialNumber(count) {
		count++;
	}
	static int count;
	virtual void display() = 0;
	virtual ~CarPart() {}
};

int CarPart::count = 0;


class Piston : public CarPart {
	int hod;
	int diameter;
public:
	Piston(unsigned n_year, std::string n_producer, int h, int d) : CarPart("Piston", n_producer,n_year), hod(h), diameter(d){}
	void display() override {
		std::cout << name << "\n" << producer << "\n" << year << "\n" << serialNumber << "\n" << hod << "\n" << diameter << "\n";
	}

	~Piston() {
	
	}
};

class Tire : public CarPart {
	int width;
	int profile;
	int diameter;
public:
	Tire(unsigned n_year, std::string n_producer, int w, int p, int d) : CarPart("Tire", n_producer, n_year), width(w),
		profile(p), diameter(d) {}
	void display() override {
		std::cout << name << "\n" << producer << "\n" << year << "\n" << serialNumber << "\n" << width << "\n" << profile << "\n" << diameter << "\n";
	}
};

class Engine : public CarPart {
	int power;
	std::vector<Piston> pistons;
public:
	Engine(unsigned n_year, std::string n_producer, int p) : CarPart("Engine", n_producer, n_year), power(p) {}
	void display() override {
		std::cout << name << "\n" << producer << "\n" << year << "\n" << serialNumber << "\n" << power << "\n";
		for (int i = 0; i < pistons.size(); i++) {
			pistons[i].display();
		}
	}
	void addPiston(const Piston& src) {
		pistons.push_back(src);
	}

};


struct Petrol {
	int octane_number;
	double price;
};

template <typename T>
class FuelTank : public CarPart {
	int volume;
	T fuel;
public:
	FuelTank(unsigned n_year, std::string n_producer, int v, const T& f):volume(v), fuel(f), CarPart("Tank", n_producer, n_year){}

};

#endif