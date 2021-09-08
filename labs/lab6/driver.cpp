#include "dog.h"

using namespace std;

int main(int argc, char**argv){

  cout << "Before instantiating Dog objects dogCount is: " << Dog::getDogCount() << endl;

  Dog dog1 = Dog("German Shepard", 5);

  dog1.printDogInfo();

  Dog dog2 = Dog("Yorkshire Terrier", 7);

  dog2.printDogInfo();

  Dog dog3 = Dog("Siberian Husky", 2);

  dog3.printDogInfo();

  Dog dog4 = Dog("Labrador Retriver", 10);

  dog4.printDogInfo();

}
