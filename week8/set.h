#ifndef _SET_H
#define _SET_H
#include <iostream>


template <typename T>
class Set {
	T** elements;
	int cap;
	int curr;
	void copy(const Set<T>& other) {
		for (int br = 0; br <= curr; br++) {
			elements[br] = new T(*(other.elements[br]));
		}
	}
	void destroy() {
		for (int br = 0; br <= curr; br++) {
			delete elements[br];
		}
		delete[] elements;
	}
	void expand() {

		T** temp = new T * [cap * 2];
		for (int br = 0; br <= curr; br++) {
			temp[br] = new T(*(elements[br]));
		}
		destroy();
		elements = temp;
		temp = nullptr;
	}
public:
	Set(int& n_cap = 0) : cap(n_cap), curr(0), elements(new T*[cap]){}
	~Set() {
		destroy();
	}
	Set(const Set<T>& other) : cap(other.cap), curr(other.curr), elements(new T* [cap]) {
		copy(other);
	}
	Set& operator=(const Set<T>& other) {
		if (this == &other)
			return *this;
		destroy();
		cap = other.cap;
		curr = other.curr;
		elements = new T * [cap];
		copy(other);
		return *this;
	}
	void add(T other) {
		if (curr == cap - 1)
			expand();
		curr++;
		elements[curr] = new T(other);
	}
	bool isEmpty(){
		return !(elements[0] == nullptr);
	}
	void print() {
		for (int br = 0; br <= curr; br++) {
			std::cout << *(elements[br]);
		}
	}
	bool contains(const T& sample) {
		for (int br = 0; br <= curr; br++) {
			if (*(elements[br]) == sample)
				return true;
		}
		return false;
	}
	Set& operator+(const Set<T>& other) {
		Set temp(cap + other.cap);
		temp.copy(*this);
		for (temp.curr; temp.curr < cap + other.curr ; temp.curr++) {
			temp.elements[temp.curr] = new T(*(other.elements[temp.curr-cap]));
		}
		return temp;
	}
	bool operator<(Set<T>& other) {
		//int max
		//cap >= other.cap ? max = cap : max = other.cap;
		for (int br = 0; br <= curr; br++) {
			if (!other.contains(*(elements[br])))
				return false;
		}
		return true;
	}
};
/*
 template <typename T>
 Set<T>::Set()
*/

#endif