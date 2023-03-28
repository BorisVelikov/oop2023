#ifndef _SIMPLE_VECTOR
#define _SIMPLE_VECTOR

class simpleVector {
	int data[10];
	short size;
public:
	simpleVector& operator+(simpleVector const&);
	simpleVector& operator-(simpleVector const&);
	simpleVector& operator*(int&);
	simpleVector& operator/(int&);	
	void print()const;
	bool zapisBin()const;
	friend simpleVector cheteneBin();
	bool zapisTXT()const;
	friend simpleVector cheteneTXT();
};


#endif // !_SIMPLE_VECTOR
