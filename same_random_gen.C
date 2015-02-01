using namespace std;

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int main()
{ ofstream out ("random", ios::out); // output file
  int num;  // how many numbers
  cin >> num;
  int low, high, range;  // range in which numbers are needed
  cin >> low >> high; cout << endl;
  range = high - low + 1;
  out << num << endl;   // write to output file
  if ( low < 0) low = -low; 
  for (int i = 1; i <= num; i++)
    out << (rand() % range - low) << " " ; // use rand() function
  out << endl;
  return 0;
}

// generates the same random numbers on every run
