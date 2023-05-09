#include<iostream>
#include <string>
#include<vector>


class shape {
	std::string label;
public:
	std::string& getLabel() {
		return label;
	}
	virtual void print() = 0;
	virtual shape* copy() = 0;
	virtual double getPerimeter() = 0;
	virtual ~shape(){}
};

class triangle :public shape {
	double a, b, c;
public:
	void print() override {
		std::cout << " /\\" << "\n";
		std::cout << "/__\\" << "\n";
	}
	double getPerimeter() override { return a + b + c; }
	shape* copy() override {
		shape* temp = new triangle(*this);
		return temp;
	}
	~triangle() override{}
};

class circle :public shape {
	double r;
public:
	void print() override {
		std::cout << "  _ \n";
		std::cout << " / \\" << "\n";
		std::cout << "|   |" << "\n";
		std::cout << " \\_/" << "\n";
	}
	double getPerimeter() override { return 3.14 * r; }
	shape* copy() override {
		shape* temp = new circle(*this);
		return temp;
	}
	~circle() override{}
};

class square :public shape {
	double a;
public:
	void print() override {
		std::cout << " __" << "\n";
		std::cout << "|  |" << "\n";
		std::cout << "|__|" << "\n";
	}
	double getPerimeter() override { return 4*a; }
	shape* copy() override {
		shape* temp = new square(*this);
		return temp;
	}
	~square() override {}
};

class shapeContainer {
	std::vector<shape*> container;
public:
	void add(shape* src) {
		shape* temp = src->copy();
		container.push_back(temp);
	}
	void info() {
		for (int i = 0; i < container.size(); i++) {
			std::cout <<container[i]->getLabel() << " "  << container[i]->getPerimeter();
		}
	}
	void print() {
		for (int i = 0; i < container.size(); i++) {
			container[i]->print();
		}
	}
};


int main() {

	return 0;
}