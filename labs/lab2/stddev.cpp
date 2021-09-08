#include "stddev.h" //includes header file
#include <iostream> //used to include standard c++ functions
#include <cmath> //used to compute square roots
#include <iomanip> //used to set precision of output

using namespace std;

void stats(float* data, int n){
//declare variables
  float avg = 0.0;
  float sum = 0.0;
  float sum2 = 0.0;
  float output = 0.0;
//find sum of data array
  for (int i = 0; i < n; i++){
    sum += data[i];
  }
//compute the mean
  avg = sum / (float)n;

  for (int j = 0; j < n; j++){
    data[j] = (data[j] - avg) * (data[j] - avg); //compute standard deviation
    //by finding the sum of the square of the result of the mean subtracted from
    //each data indice
    sum2 += data[j];
  }
  //find mean of this new sum
  output = sum2 / (float)n;

//print output with a precision of 7 and perform square root math function
  cout << "    Your Standard Deviation is : " << setprecision(7);
  cout << sqrt(output);
  cout << "\n";

}
