/*
Mike Brandin
CPSC 1021 - Section 1
21 January, 2020
*/

#include "stddev.h" //include header file
#include <iostream> //used to include standard c++ functions

using namespace std;

int main(){
  //declare variables
  float* data;//pointer
  int input;
  //prompt and scan for input
  cout << "Please enter your given number : ";
  cin >> input;
  //dynamically allocate memory for pointer
  data = new float[input];
  //set value to data members
  for (int i = 0; i < input; i++){
    data[i] = data[i] + 4 * (i + 1);

  }
  //call stats function to compute standard deviation
  stats(data, input);
  //free allocated memory
  delete(data);

  return 0;
}
