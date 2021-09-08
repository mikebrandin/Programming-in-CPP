#include "dog.h"
#include "owner.h"

using namespace std;

//initialize count value
int Dog::dogCount = 0;

//constructor
Dog::Dog(string a, int b){
  string oname;
  int oage;
  cout << "\nPlease enter owner name: ";
  cin >> oname;
  cout << "Please enter owner age: ";
  cin >> oage;
  cout << endl;

  owner = new Owner(oname, oage);

  setBreed(a);
  setAge(b);
};

//getters
string Dog::getBreed(){
  return breed;
}

int Dog::getAge(){
  return age;
}

int Dog::getDogCount(){
  return dogCount++;
}

//setters
void Dog::setBreed(string a){
  breed = a;
}

void Dog::setAge(int a){
  age = a;
}


void Dog::printDogInfo(){
  cout << "Dog " << getDogCount() << ":" << endl;
  cout << "breed:\t" << getBreed() << endl;
  cout << "age:\t" << getAge() << endl;
  cout << "owner:\t" << owner->getName() << ", " << owner->getAge() << " yo" << endl;

  delete owner;
}
