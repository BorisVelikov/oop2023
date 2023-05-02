#include "teamLeader.h"

teamLeader::teamLeader(std::vector<employee>& v, const char* proj, const char* n_name, unsigned n_wage):
employee(n_name,n_wage),team(v), project(proj){}

void operator<<(std::ostream& out, teamLeader& gosho) {
	out << (employee&)gosho;
	out << gosho.project << "\n";
	for (int i = 0; i < gosho.team.size(); i++) {
		out << gosho.team[i];
	}
}
