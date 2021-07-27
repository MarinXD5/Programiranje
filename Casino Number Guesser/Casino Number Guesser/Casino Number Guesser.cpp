// Casino Number Guesser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

void RULES() {
    cout << "+-------------------------------------------------------------------------------+" << endl;
    cout << "+  Rules of this game are:                                                      +" << endl;
    cout << "+  1. You can guess only numbers greater than 0 and lower than 10               +" << endl;
    cout << "+  2. Your bet cannot exceed more than you already have                         +" << endl;
    cout << "+  3. Correctly guessed number gets you 10x the bet                             +" << endl;
    cout << "+  4. Once your balance drops to 0 you cannot play anymore in this session      +" << endl;
    cout << "+-------------------------------------------------------------------------------+" << endl << endl;
}
int main()
{
    int guess, random_number, balance = 2500, bet;
    char answerRules, answerGame = 'Y';

    cout << "--------------------------------------------" << endl;
    cout << "-Welcome to the Casino Number Guessing Game-" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Would you like to read rules first? (Y/N)" << endl;
    cin >> answerRules;

    if (answerRules == 'Y' || answerRules == 'y') {
        RULES();
    }
    else if (answerGame == 'N' || answerGame == 'n'){
        cout << "Alright, you can proceed with the game" << endl;
    }

    cout << "Your balance is: $2500" << endl;
    cout << "Please enter your bet: ";
    cin >> bet;

    while (bet > balance) {
        cout << "You cannot bet more than what you already have! " << endl << "Please enter your bet: " << endl;
        cin >> bet;
        cout << endl;
    }
    cout << "Continuing..." << endl;

    random_number = rand() % 10 + 1;
    cout << "Random number generated!" << endl;

    while (answerGame == 'Y' ||answerGame == 'y' && balance > 0) {
        cout << "Please enter a number : ";
        cin >> guess;
        balance = balance - bet;
        while (guess < 1 || guess > 9) {
            cout << "You've entered illegal number" << endl;
            cout << "Enter another number : ";
            cin >> guess;
        }

        if (guess == random_number) {
            balance += bet;
            balance *= 10;
            cout << "That's correct answer. Your balance is now: " << balance << endl;
            cout << "Would you like to change your bet? " << endl;
            cin >> answerRules;

            if (answerRules == 'Y' || answerRules == 'y') {
                cout << "Enter your bet: ";
                cin >> bet;
            }
        }
        else {
            cout << "Your guess is wrong. " << endl;
            cout << "You lost your bet. Try again?" << endl;
            cin >> answerGame;
        }
    }
    if (answerGame == 'Y' || answerGame == 'y'){
    cout << "Woops, it seems you no longer have enough money!! :(" << endl;
    cout << "Exiting the game...";
    }
    else {
        cout << "Thanks for playing, see you next time :)";
    }

    return 0;

}
