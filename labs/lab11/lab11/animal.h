#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Animal{
public:
  //constructors
  Animal();
  Animal(int, double);
  //getters
  int getAge();
  double getWeight();
  //setters
  void setAge(int);
  void setWeight(double);
  //printer
  virtual void printInfo();

private:
  int age;
  double weight;
};

#endif
