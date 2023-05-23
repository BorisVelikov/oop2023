#ifndef _LIBRARY_H
#define _LIBRARY_H
#include<string>
#include<vector>


class BasePerson {
public:
	virtual void display() const = 0;
	virtual ~BasePerson() = 0;
	virtual BasePerson* clone() = 0;
};


class Person : public BasePerson {
protected:
	int egn;
public:
	static int count;
	Person() : egn(Person::count) { count++; }
	void display() const override;
	~Person() override{}
	BasePerson* clone() override;
};

class Student : virtual public Person {
protected:
	std::string fn;
public:
	Student(std::string num) : Person(), fn(num){}
	void display() const override;
	~Student() override{}
	BasePerson* clone() override;
};

class Teacher : virtual public Person {
protected:
	std::string department;
	std::vector<std::string> subjects;
public:
	Teacher(std::string d, std::vector<std::string> sub): Person(), department(d), subjects(sub){}
	void display() const override;
	~Teacher() override{}
	BasePerson* clone() override;
};

class Assistant : public Teacher, public Student {
public:
	Assistant(std::string d, std::vector<std::string> sub, std::string num):
		Person(), Teacher(d, sub), Student(num){}
	void display() const override;
	~Assistant() override{}
	BasePerson* clone() override;
};

class Library {
	std::vector<BasePerson*> readers;
public:
	void display();
	Library(const Library& other);
};


#endif