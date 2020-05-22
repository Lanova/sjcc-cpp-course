//===========================================
// IMPLEMENTATION
//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment: Lab Assignment 13-2 Player Kingdom
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
#include <ostream>
#include "player.h"
using namespace std;

// ============================== PLAYER =======================================
// Function:  Default constractor Player
// Precondition: none
// Purpose:  empty
Player::Player() {}

// Function:  play
// Precondition: two players defined
// Purpose: set random number as the answer, continue to play untill there is a winner,
// Calls: get_guess();
//		  checkForWin();
void Player::play(Player &player1, Player &player2)
{
	int answer = 0, guess = 0; //set both numbers to start point
	answer = rand() % 100;	   //random number from 0-99 set as an answer
	bool win = false;

	while (!win) //repeat untill the righ answer
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.get_guess();
		win = checkForWin(guess, answer);
		if (win)
			return;

		cout << "Player 2's turn to guess." << endl;
		guess = player2.get_guess();
		win = checkForWin(guess, answer);
	}
}

// Function:  checkForWin
// Precondition: two integer passed
// Purpose:  compare given number as a guess to the set answer
// 			 and print massege with low, high or win instructions
bool Player::checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You guessed " << guess << ". You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "You guessed " << guess << " Your guess is too high." << endl;

	else
		cout << "You guessed " << guess << " Your guess is too low." << endl;
	return false;
}

// Function:  virtual get_guess()
// Precondition: none
// Purpose:  returns 0
int Player::get_guess() const
{
	return 0;
}

// ============================== COMPUTERPLAYER =======================================
// Function:  Default constractor ComputerPlayer
// Precondition: none
// Purpose:  calls parent Player constructor
ComputerPlayer::ComputerPlayer() : Player() {}

// Function: virtual get_guess
// Precondition: none
// Purpose:  creates random value from 0 to 99
int ComputerPlayer::get_guess() const
{
	return rand() % 100;
}

// ============================== HUMANPLAYER =======================================
// Function:  Default constractor HumanPlayer
// Precondition: none
// Purpose: calls parent Player constructor
HumanPlayer::HumanPlayer() : Player() {}

// Function: virtual get_guess
// Precondition: none
// Purpose:  ask user for the inout and return the input as a guess
int HumanPlayer::get_guess() const
{
	int guessInput; // user guess
	cout << "Please enter your guess: ";
	cin >> guessInput; //user input
	return guessInput;
}
