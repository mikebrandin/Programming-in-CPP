#include<iostream> //include c++ standard library
#include<cmath>//include c++ standard math library

using std::pow;

// create a struct Stats below this comment
// struct members are a float variable and a pointer that can point to
// calMean, calVariance, or calStdev finctions below

//create a Stats struct to contain a float and float function pointer.
//NOTE: typedef is unneccessary in C++
struct Stats{
  float stat;
  float (*funcPoint)(float* info, int num);

};

//delclare function prototypes for construct and output functions


// add the prototype for function "construct" under this comment
// return type: float
// incoming parameters: a Struct pointer, a float, an int, and a pointer
// that can point to calMean, calVariance, or calStdev finctions above
float construct(Stats* statPoint, float* data, int n, float (*funcPointy)(float*, int));

// add the prototype for function "output" under this comment
// return type: void
// incoming parameters: three Stats pointers, and a pointer that can point
// to either min or max functions declared above

void output(Stats* statPoint1, Stats* statPoint2, Stats* statPoint3, void (*funcPointy)(Stats* s1, Stats* s2 , Stats* s3));

//delclare function prototypes for calculating mean, variance, and stdev functions
float calMean(float* data, int n);
float calVariance(float* data, int n);
float calStdev(float* data, int n);

//declare function prototypes for min and max functions
void max(Stats* s1, Stats* s2 , Stats* s3);
void min(Stats* s1, Stats* s2 , Stats* s3);
