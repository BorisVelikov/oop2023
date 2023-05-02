#include "employee.h"

employee::employee(const char* n_name, double n_wage) : name(n_name), wage(n_wage){}

void operator<<(std::ostream& out, employee& gosho) {
	out << gosho.name << "\n" << gosho.wage << "\n";
}
