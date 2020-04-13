//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Lab Assignment 7-1 Bubble Sort
// Names: Olga Sirenko & Ranjana K C
// Date: 03/15/2020
// Platform:  Linux

// Purpose:	Sort an array of numbers in ascending order, 
// i.e. smallest number is at num[0]

// Algorithm:
// 1. Take input : file Name from user
// 2. Read integers from file and store them into array
// 3. Sort Array by swapping if previous element bigger than next
// 4. Print result (cout)

// Problems I had working on this assignment (and how I overcame these problems)
// 1. Reading and storing into array - had to try and fail until found a way
// ========================================================== 
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void readFile(ifstream &fin);
// Fctn Name:  readFile
//Purpose: read the integers from the file and store them into array
//Precondition: read file with integers by reference
//Postcondition: store integers into array
// Calls: bubblesort()

void bubblesort(int ourArray[], int counter);
// Fctn Name:  bubblesort
//Purpose: Sort Array by swapping if previous element bigger than next
//Precondition: counter declare the length of used space from declered array
//Postcondition: sorted array


int main() {
 char inFileName[21];
  ifstream fin;

    cout << "Welcome to Bubble Sorter!\n";
    cout << "=======================\n";
    cout << "Which file do you want us to crunch?\n";
    cin >> inFileName;
    fin.open(inFileName);
    if (fin.fail()) // checking opening input file
    {
        cout << "Iput file opening failed\n";
        exit(1);
    }

    readFile(fin);// calling readFile function

    fin.close();
    return 0;
}

void readFile(ifstream &fin){
  const int ARRAY_SIZE = 50;
  int ourArray[ARRAY_SIZE]; // allocated memory for array size 50 
  int counter = 0; // count filled space with integers in case if there is less then 50 integers in the file
  int x;
while (counter <= ARRAY_SIZE && fin >> x && !fin.eof()) 
//checking if the counter smaller than array size - in case in file > 50 
// && if there is at least one element && if it's not end of line
    {
        ourArray[counter++] = x; // storing integers into array 
    } 
   bubblesort(ourArray, counter);// calling sort funtion
   // giving as parameters our array that we read from file and counter as an array size
}

void bubblesort(int ourArray[], int counter){
  for( int i = counter -1; i>0; i--){ // going from end to front /pivet point
    for( int k = 0; k<i; k++){ // from begging to the end interation
      if(ourArray[k]>ourArray[k+1]){// if next int is bigger then previous that we swap them
        int temp = ourArray[k+1]; // store bigger to temp 
        ourArray[k+1] = ourArray[k]; // move bigger to the right
        ourArray[k] = temp;// assign stored in temp smaller value
      }
    }
  }
  for(int i =0; i<counter; i++){//print sorted array
      cout<<ourArray[i]<<endl;
  }
}