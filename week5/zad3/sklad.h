#ifndef _SKLAD_H
#define _SKLAD_H
#include "shoeModel.h"


class Sklad {
	int cap;
	ShoeModel* models;
public:
	//big four
	Sklad(int maxModels);
	~Sklad();
	Sklad(Sklad const& other);
	Sklad& operator=(Sklad const& other);


};



#endif // !_SKLAD_H