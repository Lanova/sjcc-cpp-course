//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Bonus Assignment 3-2: Calculating Approximate Value of Pi
// Name: Olga Sirenko
// ID: 0910134
// Date: 02/16/2020
// Platform:  Linux
// ===========================================
/**
   Project A
   An approximate value of pi can be calculated using the series given below:

   pi = 4 [ 1 – 1/3 + 1/5 – 1/7 + 1/9 ... + LaTeX: \frac{\left(-1\right)^n}{2n\:+\:1}( − 1 ) n 2 n + 1 ]

   i.e. The nth term is LaTeX: \frac{\left(-1\right)^n}{2n\:+\:1}( − 1 ) n 2 n + 1 , where n = 0, 1, 2, ...

   Write a program to calculate the approximate value of pi using this
   series. The program takes an input x that determines the number of
   terms, and outputs the approximation. Note that when x = 1, n = 0.

   Project B:
   Include a loop that allows the user to repeat this calculation for
   new values n until the user says she or he wants to end the
   program.
*/
#include <iostream>
#include <iomanip>

using namespace std;
char user_input = 'n';

int main() {
  do {
    int terms = -1;
    double sum = 1.0;
    int sign = -1;
    double pi;

    cout << "Calculating Approximate Value of Pi\n" ;
    cout << "How many terms do you wanna compute pi: ";
    cin>> terms;

    //calculate pi
    for (int i = 1; i <terms; i++) {
      sum += sign / (2.0 * i + 1.0);
      sign = -sign;
    }
    pi = 4.0 * sum;

    // print pi
    cout << scientific << setprecision(10);
    cout << "Our Pi: " << pi << endl;
    // user input to repeat the programm
    cout << "Do you want to to repeat this calculation for new values n? Please enter \"Y\" for Yes ";
    cin>> user_input;
  } while(user_input == 'y'|| user_input == 'Y');

  return 0;
}

/* ==========================================================
   Problems I had working on this assignment (and how I overcame these problems)

   1. I didn't understand the formula; what does the term mean?; why
   do we need to take input from the user and where to use it.
   Had to spend time to understand math behid it to be able to solve.
   Simplified formula. Still not sure if it's correct.

   Other Things I wish to share

   1. I like to have challenges, but for me it was way harder to
   understand what should be done then to put it into the code.
   Probably I'd like to have chalenges with less deep math knowledge
   involved.

   My problem is: till the time I have no deep understanding of what
   the problem is about, I can not write it into the code.

   NOTE:
   The page https://www.desmos.com/calculator/p3zeajcgle demonstrating
   the Taylor's method *graphically and interactively* helped me to
   understand the approach outlined in the problem statement.
   ========================================================== */
