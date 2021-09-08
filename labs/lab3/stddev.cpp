#include "stddev.h" //include the header file
#include <iostream> //include c++ standard library

using namespace std;

// add implementation for function construct below this comment.
// return type: float
// incoming parameters: a Struct pointer, a float, an int, and a pointer
// that can point to calMean, calVariance, or calStdev finctions above

float construct(Stats* statPoint, float* data, int n, float (*funcPointy)(float*, int)){
  statPoint->funcPoint = funcPointy;
  statPoint->stat = funcPointy(data, n);
}


// add implementation for function output below this comment.
// return type: void
// incoming parameters: three Stats pointers, and a pointer that can point
// to either min or max functions declared above

void output(Stats* statPoint1, Stats* statPoint2, Stats* statPoint3, void (*funcPointy)(Stats* s1, Stats* s2 , Stats* s3)){
  funcPointy(statPoint1, statPoint2, statPoint3);
}

//calculate the average after taking in a float pointer and integer value

float calMean(float* data, int n){
    float mean = 0;
    for(int i = 0; i < n; i++)
    {
        mean += data[i];
    }
    return mean/float(n);
}

//calculate the variance after taking in a float pointer and integer value
float calVariance(float* data, int n){
    float mean = 0;
    for(int i = 0; i < n; i++)
    {
        mean+=data[i];
    }
    mean/=float(n);
    float variance = 0;
    for(int i = 0; i < n; i++)
    {
        variance+= pow(data[i] - mean,2.0);
    }
    return variance/n;

}

//calculate the standard deviation. taking in a float pointer and integer value
float calStdev(float* data, int n){
    float mean = 0;
    for(int i = 0; i < n; i++)
    {
        mean += data[i];
    }
    mean/=float(n);
    float variance = 0;
    for(int i = 0; i < n; i++)
    {
        variance += pow(data[i] - mean,2.0);
    }
    variance/=float(n);
    return sqrt(variance);
}


//calculate the minimum. takes input of 3 struct pointers
void min(Stats* s1, Stats* s2, Stats* s3){
    float min = 10000;
    if(s1->stat>s2->stat)
    {
        min = s2->stat;
    }
    else
    {
        min = s1->stat;
    }

    if(min > s3->stat)
        min = s3->stat;

    cout << "min: " << min << endl;
}

//calculate the maximum. takes input of 3 struct pointers
void max(Stats* s1, Stats* s2, Stats* s3){
    float max = -10000;
    if(s1->stat<s2->stat)
    {
        max = s2->stat;
    }
    else
    {
        max = s1->stat;
    }

    if(max < s3->stat)
        max = s3->stat;

    cout << "max: " << max << endl;
}
