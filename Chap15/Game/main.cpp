//===========================================
// MAIN
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment: Lab Assignment 13-2 Animal Kingdom
// Name: Olga Sirenko
// ID: 0910134
// Date: 05/10/2020
// Platform:  Linux
// ===========================================
// Include Classes:
//          1. Player(Parent)
//                1. ComputerPlayer (Child)
//                2. HumanPlayer (Child)


#include <iostream>
#include "player.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	Player a;
	HumanPlayer humanPlayer1;
	HumanPlayer humanPlayer2;
	ComputerPlayer computerPlayer1;
	ComputerPlayer computerPlayer2;
	char user_input = 'n';

	cout << "Welcome to the Land of Competitive Guessing!\n";
	cout << "============================================\n";
	cout << "Are you ready to a game of Human vs Human? (y/n)\n";
	cin >> user_input;
	if (user_input == 'y' || user_input == 'Y')
	{
		cout << "==== Human vs Human ====\n";
		cout << "Guess a number from 0 to 99\n";
		cout << "----------------------------\n";
		a.play(humanPlayer1, humanPlayer2);
	}

	cout << "Are you ready to a game of Human vs Computer? (y/n)\n";
	cin >> user_input;
	if (user_input == 'y' || user_input == 'Y')
	{
		cout << "==== Human vs Computer ====\n";
		a.play(humanPlayer1, computerPlayer1);
	}

	cout << "Are you ready to a game of Computer vs Computer? (y/n)\n";
	cin >> user_input;
	if (user_input == 'y' || user_input == 'Y')
	{
		cout << "==== Computer vs Computer ====\n";
		a.play(computerPlayer1, computerPlayer2);
	}
	return 0;
};
