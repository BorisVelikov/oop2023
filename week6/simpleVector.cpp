#include"simpleVector.h"
#include<iostream>
#include<fstream>

simpleVector& simpleVector::operator+(simpleVector const& other) {
	short maxSize;
	size > other.size ? maxSize = size : maxSize = other.size;
	for (int br = 0; br < maxSize; br++) {
		data[br] += other.data[br];
	}
}

simpleVector& simpleVector::operator-(simpleVector const& other) {
	short maxSize;
	size > other.size ? maxSize = size : maxSize = other.size;
	for (int br = 0; br < maxSize; br++) {
		data[br] -= other.data[br];
	}
}

simpleVector& simpleVector::operator*(int& other) {
	for (int br = 0; br < size; br++) {
		data[br] *= other;
	}
}

simpleVector& simpleVector::operator/(int& other) {
	for (int br = 0; br < size; br++) {
		data[br] /= other;
	}
}

void simpleVector::print()const {
	std::cout << size << "/n";
	for (int br = 0; br < size; br++) {
		std::cout << data[br];
	}
	std::cout << '/n';
}

bool simpleVector::zapisBin()const {
	std::ofstream ofile("vector.bin", std::ios::binary | std::ios::_Noreplace | std::ios::app);
	if (!ofile.is_open()) {
		std::cout << "Error opening file!/n";
		return 0;
	}
	ofile.write((char*)this, sizeof(simpleVector));
	ofile.close();
	return 1;
}

simpleVector cheteneBin() {
	simpleVector temp;
	std::ifstream ifile("vector.bin", std::ios::binary);
	ifile.read((char*)&temp, sizeof(simpleVector));
	ifile.close();
	return temp;
}

bool simpleVector::zapisTXT()const {
	std::ofstream ofile("vector.bin", std::ios::_Noreplace | std::ios::app);
	if (!ofile.is_open()) {
		std::cout << "Error opening file!/n";
		return 0;
	}
	ofile.write((char*)this, sizeof(simpleVector));
	ofile.close();
	return 1;
}

simpleVector cheteneTXT() {
	simpleVector temp;
	std::ifstream ifile("vector.bin", std::ios::in);
	ifile.read((char*)&temp, sizeof(simpleVector));
	ifile.close();
	return temp;
}