#include<fstream>
#include<iostream>
#include"F1Team.h"

bool F1Team::zapis()const {
	std::ofstream ofile("car.bin", std::ios::binary);
	if (!ofile.is_open()) {
		std::cout << "Error opening file!/n";
		return 0;
	}
	ofile.write((char*)this, sizeof(F1Team));
	ofile.close();
	return 1;
}

F1Team chetene() {
	std::ifstream ifile("car.bin", std::ios::binary);
	if (!ifile.is_open()) {
		ifile.close();
		std::cerr << "Error opening file!/n";
		//return 0;
	}
	F1Team team;
	ifile.read((char*)&team, sizeof(team));
	ifile.close();
	return team;
}