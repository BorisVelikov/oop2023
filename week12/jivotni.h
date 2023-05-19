#ifndef _MAGARE_H
#define _MAGARE_H
#define _CRT_SECURE_NO_WARNINGS
#include<string>

enum food {plant, meat, both};


class animal {
protected:
	char* name;
	int weight;
	food lapanica;
public:
	static int count;
	int eat();
	virtual int getFood() const;
	virtual ~animal() {
		delete[] name;
	}
	animal(const char* n_name, int w, food maaro);
	animal(const animal& other);
	animal& operator=(const animal& other);
	virtual void foo() = 0;
};

class mammal :public animal {
	char* osinovitel;
public:
	mammal(const char* n_name, int w, food maaro, char* pesho);
	~mammal() override;
	mammal(const mammal& other);
	mammal& operator=(const mammal& other);
	void foo() override{}
};

class bird : public animal {
	std::string city;
public:
	bird(const char* n_name, int w, food maaro, std::string grad);
};


#endif