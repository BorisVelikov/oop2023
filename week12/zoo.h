#ifndef _ZOO_H
#define _ZOO_H
#include<vector>
#include"jivotni.h"


template <typename pleskavica>
class zooSector {
	std::vector<pleskavica> animals;
	int x;
	int y;
public:
	void add(const pleskavica& pesho) {
		animals.push_back(pesho);
	}
};
/*
class zoo {
	std::string name;
	zooSector<bird> birds;
	zooSector<mammal> mammals;
};
*/

#endif
