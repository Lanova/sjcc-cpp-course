//===========================================
// INTERFACE
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
#include <istream>
#include <cstdlib>
using namespace std;

// ============================== PLAYER =======================================
#ifndef PLAYER_H
#define PLAYER_H
class Player // parent class - base for HumanPlayer and ComputerPlayer
{
public:
 int guess; //user or compu

// Function:  Default constractor Player
// Precondition: none
// Purpose:  empty
   Player();

// Function:  play
// Precondition: two players defined
// Purpose: set random number as the answer, continue to play untill there is a winner, 
// Calls: get_guess();
//		  checkForWin(); 
   void play(Player &player1, Player &player2);

// Function:  checkForWin
// Precondition: two integer passed
// Purpose:  compare given number as a guess to the set answer
// 			 and print massege with low, high or win instructions
   bool checkForWin(int guess, int answer);

// Function:  virtual get_guess()
// Precondition: none
// Purpose:  returns 0
   virtual int get_guess() const;
};
#endif /* PLAYER_H*/

// ============================== COMPUTERPLAYER =======================================
#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
class ComputerPlayer : public Player
{
public:
// Function:  Default constractor ComputerPlayer
// Precondition: none
// Purpose:  calls parent Player constructor
   ComputerPlayer();

// Function: virtual get_guess
// Precondition: none
// Purpose:  creates random value from 0 to 99 
   virtual int get_guess() const;
};
#endif /*COMPUTERPLAYER_H*/


// ============================== HUMANPLAYER =======================================
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
class HumanPlayer : public Player
{
public:
// Function: virtual get_guess
// Precondition: none
// Purpose:  ask user for the inout and return the input as a guess 
   HumanPlayer();
   virtual int get_guess() const;
};
#endif /*HUMANPLAYER_H*/
