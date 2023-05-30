#ifndef _QUESTION_H
#define _QUESTION_H
#include <iostream>
#include<string>
#include<vector>


class Question {
protected:
	std::string studentAnswer;
	int points;
	std::string text;
public:
	static bool validYesNoAnswer(const std::string& ans);
	static bool correctYesNoAnswer(const std::string& ans, bool correct_is_yes);
	static const std::string YES;
	static const std::string NO;
	virtual void ask() = 0;
	virtual int grade() = 0;
	void print();
	virtual ~Question(){}
	Question(int p, const std::string& t) :points(p), text(t), studentAnswer("") {}
};


class YesNoQuestion : public Question {
protected:
	bool right;
public:
	YesNoQuestion(int p, const std::string& t, bool r);
	void ask() override;
	int grade() override;
	~YesNoQuestion() override{}
};

class MultipleChoiceQuestion : public Question {
	std::vector<YesNoQuestion> questions;
public:
	MultipleChoiceQuestion(int p, const std::string& t, std::vector<std::string> txts, std::vector<bool> ans);
};



#endif