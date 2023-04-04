#ifndef POWER_H
#define POWER_H
#include <string>

class Power {
	std::string name;
	int damage;
public:
	Power(const std::string& n_name, int n_damage);

	const std::string& getName() const;
	int getDamage() const;

	bool operator<(const Power& other);
};

#endif  // POWER_H
