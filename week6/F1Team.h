#ifndef _F1TEAM
#define _F1TEAM
#include"F1Car.h"

class F1Team {
	char name [32] ;
	F1Car cars[2];
public:
	bool zapis()const;
	friend F1Team chetene();
};



#endif // !_F1TEAM
