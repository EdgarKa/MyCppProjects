// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Guesser.h"

using namespace std;

void toPlayAgain();

int main()
{
    cout << "Hangman! Guess the word. To list the letters you typed type \'#\'. Good luck!\n\n";
    Guesser guesser;
    while (!guesser.ifWordIsGuessed())
    {
        cout << "Enter a character in word " << guesser.getMarkedWord() << " > ";
        char a;
        cin >> a;
        guesser.mainGame(a);
    }

    toPlayAgain();    
    
    return 0;
}

void toPlayAgain()
{
    char a;
    do {
        std::cout << "Would you like to play again? (y/n) > ";
        std::cin >> a;
        if (a == 'Y' || a == 'y')
        {
            //////////////////////////
            Guesser guesser;
            while (!guesser.ifWordIsGuessed())
            {
                cout << "Enter a character in word " << guesser.getMarkedWord() << " > ";
                char a;
                cin >> a;
                guesser.mainGame(a);
            }
            //////////////////////////
        }
        else if (a == 'n' || a == 'N')
            break;
        else
            std::cout << "Input is misunderstood. Try again.\n";
    } while (a != 'y' || a != 'n' || a != 'Y' || a != 'N');
}

