#include "Guesser.h"
#include <iostream>
#include <algorithm>

Guesser::Guesser()
{
	word = "asterisk"; // guessedWord
	isWordGuessed = false; // if it's guessed or not
	incorrectAttempts = 0;
	guessedChars = ""; // if user inputs the same char

	for (int i = 0; i < word.length(); i++)
		markedWord += '*';
}

std::string Guesser::getMarkedWord()
{
	return markedWord;
}

// checks if the word is guessed
bool Guesser::ifWordIsGuessed()
{
	if (word == markedWord)
		return true;
	else return false;
}

void Guesser::mainGame(char a)
{
	// If user wants to list characters
	if (a == '#')
	{
		hashListCharasters();
		return;
	}
	
	bool isIt = checkIfAlreadyInTheWord(a);

	if (isIt == true)
		findLetterInWord(a);
	

	if (word == markedWord)
	{
		isWordGuessed = true;
		results();
		
	}
}

void Guesser::hashListCharasters()
{
	std::sort(guessedChars.begin(), guessedChars.end());
	for (char c : guessedChars)
		std::cout << c << " ";
	std::cout << "\n";
}

bool Guesser::checkIfAlreadyInTheWord(char a)
{
	for (char c : guessedChars)
	{
		if (c == a)
		{
			std::cout << "\t" << c << " is already in the word\n";
			return false;
		}
	}
	return true;
}

void Guesser::findLetterInWord(char a)
{
	bool found = false;
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == a)
		{
			markedWord[i] = a;
			found = true;
		}

	}
	if (found == false)
	{
		std::cout << "\t" << a << " is not in the word\n";
		incorrectAttempts++;
	}
	guessedChars += a;
}

void Guesser::results()
{
	if (incorrectAttempts == 0)
		std::cout << "The word is " << markedWord << ". You missed " << incorrectAttempts << " times. Impressive!\n\n";
	else if (incorrectAttempts == 1)
		std::cout << "The word is " << markedWord << ". You missed " << incorrectAttempts << " time.\n\n";
	else
		std::cout << "The word is " << markedWord << ". You missed " << incorrectAttempts << " times.\n\n";

}