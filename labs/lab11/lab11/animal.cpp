#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "animal.h"

//constructors
Animal::Animal(){
  setAge(0);
  setWeight(0);
}
Animal::Animal(int a, double w){
  setAge(a);
  setWeight(w);
}
//getters
int Animal::getAge(){
  return age;
}
double Animal::getWeight(){
  return weight;
}
//setters
void Animal::setAge(int a){
  age = a;
}
void Animal::setWeight(double w){
  weight = w;
}
//printer
void Animal::printInfo(){
  cout << "Age: " << getAge() << "\nWeight: " << getWeight() << endl << endl;
}
