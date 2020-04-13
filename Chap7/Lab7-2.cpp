//===========================================
// Course: CIS 054 (100616) C/C++ Programming
// Project: Lab Assignment 7B-1 Counting Occurrences
// Names: Olga Sirenko
// Date: 03/21/2020
// Platform: Linux

// Write a program that reads in a list of 50 or less integers from a file into an array, and output the number of occurrence of each integer present in the file.
// The output will be a two-column list. The first column is a list of the distinct integer, sorted from smallest to largest (ascending order).
// The second column is the count of each integer. See lecture video 7-5 for discussion of this homework.

// Algorithm:
// 1. Take input: file Name from user
// 2. Connect file stream and store them into array
// 3. Create hash map where numbers stored as a key and occurences like a value
// 4. Output result into two columns

// Problems I had working on this assignment (and how I overcame these problems)
//with sorting hash table - > changed unordere_map to map & printing smaller data first
// ==========================================================

#include <iostream>
#include <fstream>
#include <map>


using namespace std;
void read_file(ifstream &fin);
//Purpose: Connect to file stream
//        if the file cannot be opened, the program will exit
//        read file stream, populate the array arr with integers from fin
//Assumption: user's file has less than 50 integers
//Postcondition: fin has been successfully connected to the file & store integers into array
// Calls: creat_hashmap()

void creat_hashmap(int arr[], int size_arr);
//Purpose: store array integers as keys and occurences as value
// Precondition:
//         arr - arr[] has been populated with integers from file stream
//         size - the number of integers we got
//Postcondition:
//          arr[] is sorted ascending
//          aoccurences are counted
//          printed into two columns(Integer and Occurrence)

int main()
{
  char inFileName[21];
  ifstream fin;
 
  cout << "Welcome to Number Cruncher!\n";
  cout << "=======================\n";
  cout << "Which file do you want us to crunch?\n";
  cin >> inFileName; //get file name
  fin.open(inFileName);
  if (fin.fail()) // checking opening input file
  {
    cout << "Iput file opening failed\n";
    exit(1);
  }

  read_file(fin);

  fin.close();
  return 0;
}

void read_file(ifstream &fin)
{
  const int ARRAY_SIZE = 50;
  int arr[ARRAY_SIZE];
  int size = 0;
  int x;
  while (size <= ARRAY_SIZE && fin >> x && !fin.eof())
  //checking if the size smaller than array size - in case in file > 50
  // && if there is at least one element && if it's not end of line
  {
    arr[size++] = x;
  }
  creat_hashmap(arr, size); // calling creat hashmap funtion
}

void creat_hashmap(int arr[], int size)
{
  map<int, int> hashmap;

  for (int i = 0; i < size; i++)
  {
    hashmap[arr[i]]++;
  }

  cout << "Here is the stats:\n";
  cout << "Number"
       << "\t"
       << "Count" << endl;
  // iterating the map and printing sorted integers by key
  for (auto i = hashmap.begin(); i != hashmap.end(); i++)
  {
    cout << i->first << "\t" << i->second << endl;
  }
}
