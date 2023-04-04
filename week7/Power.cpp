#include"Power.h"

Power::Power(const std::string& n_name, int n_damage): name(n_name), damage(n_damage){}

const std::string& Power::getName() const {
	return name;
}

int Power::getDamage() const
{
	return damage;
}

bool Power::operator<(const Power& other) {
	return damage < other.damage;
}