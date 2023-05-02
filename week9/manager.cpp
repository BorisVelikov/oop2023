#include"manager.h"

void operator<<(std::ostream& out, manager& gosho) {
	out << (employee&)gosho;
	for (int i = 0; i < gosho.leaders.size(); i++) {
		out << gosho.leaders[i];
	}
}

int manager::loss() {
	double total = 0;
	total += wage;
	for (int i = 0; i < leaders.size(); i++) {
		total += leaders[i].getWage();
		for (int j = 0; j < leaders[i].getTeam().size(); j++) {
			total += leaders[i].getTeam()[j].getWage();
		}
	}
	return wage;
}
