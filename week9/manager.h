#ifndef _MANAGER_H
#include"employee.h"
#include"teamLeader.h"

class manager : public employee {
	std::vector<teamLeader> leaders;
public:
	manager(std::vector<teamLeader>& v):leaders(v){}
	friend void operator<<(std::ostream& out, manager& gosho);
	int loss();
};

#endif // !_MANAGER_H
