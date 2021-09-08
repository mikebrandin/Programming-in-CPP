/*
Mike Brandin
CPSC 1021
2/11/2020
*/

#ifndef CAR_H
#define CAR_H

using namespace std;

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class Car;

class Car {
private:
  string make;
  string model;
  int year;
  double price;

public:
Car(){}//constructor

~Car(){}//destructor
//mutators
void setMake(string m) {make = m;}

void setModel(string o) {model = o;}

void setYear(int y) {year = y;}

void setPrice(double p) {price = p;}

//accessors
string getMake() {return make;}

string getModel() {return model;}

int getYear() {return year;}

float getPrice() {return price;}

void printCarInfo(){
  ofstream out_file;
  out_file.open("formatted.data", std::ios_base::app);
  out_file << "Make:     " <<  right << setw(7) << getMake() << endl;
  out_file << "Model:    " <<  right << setw(7)  << getModel() << endl;
  if(!isClassic()){
    out_file << "Year:     " << right << setw(7)  << getYear() << endl;
  }
  else{
    out_file << "Year:     " << right << setw(7) << getYear();
    out_file << " (classic)" << endl;

  }
  out_file << "Price:" << right << setw(3) <<  "$" << fixed << setprecision(2) << getPrice() << endl;

  out_file.close();

}

bool isClassic(){
  if ((2020 - getYear()) < 30){
    return false;
  }
  else{
    return true;
  }
}

};
#endif
