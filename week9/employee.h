#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include<string>
#include<iostream>
#include<vector>
//#include"teamLeader.h"

class employee {
protected:
	std::string name;
	double wage;
public:
	//friend class teamLeader;
	//friend class employee;
	int getWage() { return wage; }
	employee(const char* n_name = "\0", double n_wage = 0);
	friend void operator<<(std::ostream& out, employee& gosho);
};



#endif