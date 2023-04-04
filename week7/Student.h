#ifndef STUDENT_H
#define STUDENT_H

#include <string>

#include "Power.h"


class Student {
	std::string name;
	std::string house;
	Power const* power;
	int health;
public:
	//Student();
	Student(const std::string& n_name);

	const std::string& getName() { return name; }
	const std::string& getHouse() { return house; }
	void setHouse(const std::string& n_house) { house = n_house; }
	int getHealth() { return health; }
	void takeDamage(int n_damage) { health -= n_damage; }
	void setPower(const Power* n_power);
	const Power* getPower() { return power; }
	bool isAlive() { return health > 0; }
	int attack() { return power->getDamage(); }
};

#endif // STUDENT_H