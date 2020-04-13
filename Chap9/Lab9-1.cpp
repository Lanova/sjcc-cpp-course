//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Lab Assignment 9-1 Sum and Average Program 2
// Name: Olga Sirenko
// ID: 0910134
// Date: 04/03/2020
// Platform:  Linux
// ===========================================
// Algoritm:
//    1. Ask user for an input file name
//    2. Read from the file doubles
//    3. Store data into dynamic array
//    4. Print out
//       4.1 the sum and average of all the array[i]s greater than or equal to zero,
//       4.2 the sum and average of all the array[i]s less than zero,
//       4.3 the sum and average of all the array[i]s, whether positive, negative or zero.
// Requirement for Formating:
//      1. The program will loop again to ask if the user wants to process another file
//      2. Use dynamic array to hold just the right array[i] of floating-point array[i]s read from file
//      3. Remember to comment well in your program and any functions you use
// ===========================================
// Problems:
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    char inFileName[21];
    ifstream fin;
    char user_input = 'n';

    cout << "Sum and Average Program 2\n";
    cout << "=======================\n";
    do
    {
        double *array = NULL;
        double temp = 0.0, sum = 0.0, avr = 0.0, pos_sum = 0.0, neg_sum = 0.0, pos_avr = 0.0, neg_avr = 0.0;
        int count = 0, pos_count = 0, neg_count = 0;

        cout << "Which file do you want us to read?\n";
        cin >> inFileName;
        fin.open(inFileName);

        if (fin.fail()) // checking opening input file
        {
            cout << "Iput file opening failed\n";
            exit(1);
        }

        while (fin >> temp)
        {
            count++;
        }
        array = new double[count];
        fin.close();
        fin.open(inFileName);

        for (int i = 0; i < count; i++)
        {
            fin >> array[i];
            sum += array[i];
            if (array[i] >= 0)
            {
                pos_sum += array[i]; // POSITIVE numbers
                pos_count++;
                pos_avr = pos_sum / pos_count;
            }
            else
            {
                neg_sum += array[i]; //NEGATIVE numbers
                neg_count++;
                neg_avr = neg_sum / neg_count;
            }
        }
        avr = sum / count;
        cout << fixed << setprecision(2);
        //Output
        cout << "For positive numbers, occurrence = " << pos_count << " sum = " << pos_sum << " and average = " << pos_avr << endl;
        cout << "For negative numbers, occurrence = " << neg_count << " sum = " << neg_sum << " and average = " << neg_avr << endl;
        cout << "For all numbers, occurrence = " << count << " sum = " << sum << " and average = " << avr << endl;
        fin.close();
        delete[] array;

        cout << "Do you want to enter another name? (y/n)\n";
        cin >> user_input;
    } while (user_input == 'y' || user_input == 'Y');
    return 0;
}
