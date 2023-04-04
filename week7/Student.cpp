#include"Student.h"

Student::Student(const std::string& n_name):name(n_name){}

void Student::setPower(const Power* n_power) {
	power = n_power;
}
