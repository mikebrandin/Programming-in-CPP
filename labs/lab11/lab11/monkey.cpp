#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "animal.h"
#include "monkey.h"

//constructor
Monkey::Monkey(string n, string v){

  setName(n);
  setVoice(v);
  setAge(5);
  setWeight(23.61);

}

//getters
string Monkey::getName(){
  return name;
}
string Monkey::getVoice(){
  return soundsLike;
}
//setters
void Monkey::setName(string n){
  name = n;
}
void Monkey::setVoice(string v){
  soundsLike = v;
}
//printer
void Monkey::printInfo(){
  cout << "Monkey Info:\n" << "Name: " << getName() << "\nVoice: " << getVoice() << endl;
  cout << "Age: " << getAge() << "\nWeight: " << getWeight() << endl << endl;

}
