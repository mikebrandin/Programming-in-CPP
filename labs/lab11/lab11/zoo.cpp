#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#include "animal.h"
#include "monkey.h"
#include "tiger.h"

int main(int argc, char* argv[]){
  vector<Animal*> myAnimals;

  Tiger t1("Carole", "Roar!");
  myAnimals.push_back(&t1);


  Tiger t2("Joe", "Roar!");
  myAnimals.push_back(&t2);


  Monkey m1("Maurice", "Screeeech!!!");
  myAnimals.push_back(&m1);


  Monkey m2("Julian", "Screeeech!!!");
  myAnimals.push_back(&m2);


  for (unsigned int i = 0; i < myAnimals.size(); i++){
    myAnimals[i]->printInfo();
  }

}
