#include "question.h"

const std::string Question::YES = "yes";
const std::string Question::NO = "no";

bool Question::validYesNoAnswer(const std::string& ans) {
	return (ans == YES || ans == NO);
}

bool Question::correctYesNoAnswer(const std::string& ans, bool correct_is_yes) {
	return (correct_is_yes == true && ans == YES) || (correct_is_yes == false && ans == NO);
}

YesNoQuestion::YesNoQuestion(int p, const std::string& t, bool r) :
	Question(p, t), right(r){}

void YesNoQuestion::ask() {
	std::cout << text << "\n";
	std::cin >> studentAnswer;
	std::cout << grade();
}

int YesNoQuestion::grade() {
	if (correctYesNoAnswer(studentAnswer, right))
		return points;
	return 0;
}

void Question::print() {
	std::cout << text;
}

MultipleChoiceQuestion::MultipleChoiceQuestion(int p, const std::string& t, std::vector<std::string> txts, std::vector<bool> ans) :
	Question(p, t) {
	questions.resize(ans.size(),);
	questions.erase(questions.begin());

	for(int i=0; i<ans.size())
}