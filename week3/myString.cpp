#include <iostream>
#include "myString.h"
#include <cstring>

MyString::MyString() : len(1) {
	start = new char[1];
	*start = '/0';
}

//big four

MyString::~MyString() {
	delete[] start;
	start = nullptr;
}

MyString::MyString(MyString const& other) : len(other.len) {
	start = new char[len];
	strcpy(start, other.start);
}

MyString& MyString::operator=(MyString const& other) {
	len = other.len;
	delete[] start;
	start = new char[len];
	strcpy(start, other.start);
	return *this;
}

//funcs

int MyString::length() {
	return len - 1;
}

MyString::MyString(const char* other) : len(strlen(other)+1) {
	start = new char[len];
	strcpy(start, other);
}

char& MyString::at(unsigned i) {
	if (i >= len) {
		throw std::exception("losho!");
	}
	return start[i];
}