#include <iostream>
#include <fstream>

int main() {
	std::ifstream iFile;
	iFile.open("test.txt");
	iFile.seekg(0, std::ios::end);
	int result = iFile.tellg();
	iFile.close();
	std::cout << result;
	return 0;
}