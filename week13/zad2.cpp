#include "zad2.h"
#include<iostream>
int Person::count = 0;

void Person::display() const {
	std::cout << egn << "\n";
}

BasePerson* Person::clone() {
	Person* temp;
	temp = new Person(*this);
	return temp;
}

void Student::display() const {
	Person::display();
	std::cout << fn << "\n";
}

BasePerson* Student::clone() {
	Student* temp;
	temp = new Student(*this);
	return temp;
}

void Teacher::display() const {
	Person::display();
	std::cout << department << "\n";
	for (int i = 0; i < subjects.size(); i++) {
		std::cout << subjects[i] << "\n";
	}
}

BasePerson* Teacher::clone() {
	Teacher* temp = new Teacher(*this);
	return temp;
}

void Assistant::display() const {
	Student::display();
	Teacher::display();
}

BasePerson* Assistant::clone() {
	Assistant* temp = new Assistant(*this);
	return temp;
}

void Library::display() {
	for (int i = 0; i < readers.size(); i++) {
		readers[i]->display();
	}
}

Library::Library(const Library& other) : readers(other.readers) {
	for (int i = 0; i < readers.size(); i++) {
		readers[i] = other.readers[i]->clone();
	}
}
