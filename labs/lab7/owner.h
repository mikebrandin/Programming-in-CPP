#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <string>

using namespace std;

class Owner{
  private:
  string name;
  int age;

  public:
  Owner(string, int);
  Owner();
  ~Owner(){};

  string getName();
  int getAge();


};

#endif
