#include "owner.h"

Owner::Owner(string a, int b){
  name = a;
  age = b;

};

Owner::Owner(){
  name = " ";
  age = 0;
};

string Owner::getName(){
  return name;
}

int Owner::getAge(){
  return age;
}
