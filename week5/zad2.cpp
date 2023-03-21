#include <fstream>
#include <iostream>

int main() {
	std::ifstream file("zad2.cpp");
	char ch;
	while (!file.eof()) {
		file.get(ch);
		std::cout << ch;
	}	
	file.close();
	return 0;
}