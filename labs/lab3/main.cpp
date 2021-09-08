/*
Mike Brandin
CPSC 1021
January 30th, 2020
*/

#include "stddev.h"
#include <iostream>

using namespace std;

int main()
{
   int n = 0;
   cout << "Please type the size of your array : " << endl;
   cin >> n;

   float* data = new float[n];

   for(int i = 0; i < n; i++)
   {
       data[i] = (i+1)*4;
       cout << "data: " << data[i] << endl;
   }


   // declare three Stats pointers below named mean, variance, and stdev
   // and allocate memory for each of the using malloc, calloc or new

//declare mean, variance, and stdev as struct pointers and allocate memory
  Stats* mean = new Stats;
  Stats* variance = new Stats;
  Stats* stdev = new Stats;


   // calling function construct to calculate the mean
   construct(mean, data, n, calMean);


   // print the mean below this comment
   cout << "mean: " << mean->stat << endl;
   //struct members are a float variable and a pointer that can point to

   // calling function construct to calculate the variance
   construct(variance, data, n, calVariance);


   // print the variance below this comment
   cout << "variance: " << variance->stat << endl;

   // calling function construct to calculate the stdev
   construct(stdev, data, n, calStdev);


   // print the stddev below this comment
   cout << "stddev: " << stdev->stat << endl;


   // calling function output with min and max
   output(mean, variance, stdev, min);
   output(mean, variance, stdev, max);

   // free memory that you have allocated above for the three pointers to Stats here

//c++ operator to free allocated memory
    delete(mean);
    delete(variance);
    delete(stdev);

}
