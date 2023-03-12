#ifndef _MY_STRING_H
#define _MY_STRING_H

class MyString {
	int len;
	char* start;
public:
	//big four
	MyString();
	~MyString();
	MyString(MyString const& other);
	MyString& operator=(MyString const& other);
	//funcs
	int length();
	MyString(const char* other);
	char& at(unsigned i);
};


#endif