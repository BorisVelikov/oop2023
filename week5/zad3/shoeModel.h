#ifndef _SHOE_MODEL_H
#define _SHOE_MODEL_H
//#include <cstring>

class ShoeModel {
	char* producer;
	char* modelName;
	double price;
	double rating;
	int inStock;
public:
	//big four
	ShoeModel();
	~ShoeModel();
	ShoeModel(ShoeModel const& other);
	ShoeModel& operator=(ShoeModel const& other);
};





#endif // !_SHOE_MODEL_H