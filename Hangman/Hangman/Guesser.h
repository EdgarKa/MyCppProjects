#pragma once
#include <string>
class Guesser {
public:
	Guesser();
	std::string getMarkedWord();
	bool ifWordIsGuessed();
	void mainGame(char);

private:
	void hashListCharasters();
	bool checkIfAlreadyInTheWord(char);
	void findLetterInWord(char);
	void results();

	std::string word;
	std::string markedWord;
	bool isWordGuessed;
	bool gameCondition;
	int incorrectAttempts;
	std::string guessedChars;	
};
