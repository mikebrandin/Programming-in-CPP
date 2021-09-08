#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "animal.h"
#include "tiger.h"

//constructor
Tiger::Tiger(string n, string v){

  setName(n);
  setVoice(v);
  setAge(10);
  setWeight(311.49);
}

//getters
string Tiger::getName(){
  return name;
}
string Tiger::getVoice(){
  return soundsLike;
}
//setters
void Tiger::setName(string n){
  name = n;
}
void Tiger::setVoice(string v){
  soundsLike = v;
}
//printer
void Tiger::printInfo(){
  cout << "Tiger Info:\n" << "Name: " << getName() << "\nVoice: " << getVoice() << endl;
  cout << "Age: " << getAge() << "\nWeight: " << getWeight() << endl << endl;
}
