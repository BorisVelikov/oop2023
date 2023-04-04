#include"Hogwarts.h"

Hogwarts::Hogwarts(const Hogwarts& other) : len(other.len), cap(other.cap) {
	studs = new Student * [cap];
	for (int br = 0; br < len; br++) {
		studs[br] = new Student(*(other.studs[br]));
	}
}

Hogwarts::Hogwarts(Hogwarts&& other) : len(other.len), studs(other.studs), cap(other.cap) {
	other.studs = nullptr;
}

Hogwarts& Hogwarts::operator=(const Hogwarts& other) {
	if (this != &other) {
		for (int br = 0; br < len; br++) {
			delete studs[br];
		}
		delete[] studs;
		len = other.len;
		cap = other.cap;
		studs = new Student * [len];
		for (int br = 0; br < len; br++) {
			studs[br] = new Student(*(other.studs[br]));
		}
	}
	return *this;
}

Hogwarts& Hogwarts::operator=(Hogwarts&& other) {
	for (int br = 0; br < len; br++) {
		delete studs[br];
	}
	delete[] studs;
	len = other.len;
	cap = other.cap;
	studs = other.studs;
	other.studs = nullptr;
}

Hogwarts::~Hogwarts() {
	for (int br = 0; br < len; br++) {
		delete studs[br];
	}
	delete[] studs;
}

void Hogwarts::addStudent(const Student& student) {
	if (len == cap+1) {
		cap != 0 ? cap += 2 : cap *= 2;
		Student** temp;
		for (int br = 0; br < len; br++) {
			*(temp[br]) = *(studs[br]);
			delete studs[br];
		}
		delete[] studs;
		studs = temp;
		temp = nullptr;
	}
	*(studs[len++]) = student;
}

std::ostream& operator<<(std::ostream& out, const Hogwarts& hogwarts) {
	for (int br = 0; br < hogwarts.len; br++, out << '\n') {
		out << hogwarts.studs[br]->getName() << " from house " << hogwarts.studs[br]->getHouse();
	}
}
