#ifndef _TEAM_LEADER_H
#define _TEAM_LEADER_H
#include "employee.h"
#include <vector>
#include"manager.h"

class teamLeader : public employee {
protected:
	std::string project;
	std::vector<employee> team;
public:
	//friend class employee;
	int getWage() { return wage; }
	std::vector<employee>& getTeam() {
		std::vector<employee>& ref = team;
		return ref;
	}

	friend class manager;
	teamLeader(std::vector<employee>& v, const char* proj = "\0", const char* n_name = "\0", unsigned n_wage=0);
	friend void operator<<(std::ostream& out, teamLeader& gosho);
};


#endif // ! _TEAM_LEADER_H
