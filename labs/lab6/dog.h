#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

#include "owner.h"

using namespace std;


class Dog{
  private:
  string breed;
  int age;
  Owner* owner;
  static int dogCount;

  public:
  //constructors
  Dog(string, int);
  Dog(){};
  //destructors
  ~Dog(){};

  //getters
  string getBreed();
  int getAge();
  static int getDogCount();
  //setters
  void setBreed(string);
  void setAge(int);
  //print info
  void printDogInfo();


};

#endif
