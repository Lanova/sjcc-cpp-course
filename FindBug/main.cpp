/* 
File: 		demo14_3a_rpn.cpp
Purpose: 	demo how to use stack to implement RPN calculation
Author & copyright: Monza Lui
Date:		Dec 1, 2019
Demo Description:
(Book ex. 10) Reverse Polish Notation (RPN), or postfix notation, is a format to specify
mathematical expressions. In RPN, the operator comes after the operands
instead of the normal format in which the operator is between the operands
(this is called infix notation). Starting with an empty stack, a RPN
calculator can be implemented with the following rules:
■ If a number is input, push it on the stack.
■ If "+" is input, then pop the last two operands off the stack, add
them, and push the result on the stack.
■ If "-" is input then pop value1, pop value2, then push value2-
value1 on the stack.
■ If "*" is input, then pop the last two operands off the stack, multiply
them, and push the result on the stack
■ If "/" is input them pop value1, pop value2, then push value2/
value1 on the stack
■ If "q" is input, then stop inputting values, print out the top of the
stack, and exit the program
Modify the Stack class given in Section 13.2 to store integers instead
of characters. Use the modified stack to implement a RPN calculator.
Output an appropriate error message if there are not two operands on the
stack when given an operator. Here is a sample input and output that is
equivalent to ((10 - (4 + 3)) * 8)/5:
10 4 3 + - 8 * 6 / q
The top of the stack is: 4
*/
#include <iostream>
#include "stack.h"
using namespace std;

#define DEBUG

int main()
{

	Stack rpn;
	char c;
	double num, op1, op2, result;

	cout << "Welcome to Reverse Polish Notation Calculator!\n";
	cout << "Please enter your expression - separate each element by spaces inbetween,"
		 << "and end with a letter 'q'.\n";

	// Mechanism:
	// 1. When input is a number
	//		1. push into the stack
	// 2. When input is an operator
	//		1. pop 2 numbers from stack
	//		2. place first number as second operant
	//		3. place second number as first operant
	// 		4. Do the math
	//		5. Push result into stack
	//	3. Repeat above
	while ((cin >> c) && (c != 'q'))
	{
		if (isdigit(c))
		{
			cin.putback(c);
			cin >> num;
			rpn.push(num);
#ifdef DEBUG
			cout << num << "=" << num << endl;
#endif
		}
		else
		{
			op2 = rpn.pop();
			op1 = rpn.pop();
			switch (c)
			{
			case '+':
				result = op1 + op2;
				break;
			case '-':
				result = op1 - op2;
				break;
			case '*':
				result = op1 * op2;
				break;
			case '/':
				result = (op1 * 1.0) / op2;
				break;
			default:
				cout << "Illegal operator\n";
				exit(1);
			}
#ifdef DEBUG
			cout << op1 << c << op2 << "=" << result << endl;
#endif
			rpn.push(result);
		}
	}

	cout << "Result = " << rpn.pop() << endl;

	return 0;
}