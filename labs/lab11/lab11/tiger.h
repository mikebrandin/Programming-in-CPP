#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Tiger : public Animal{
public:
  //constructor
  Tiger(string, string);
  //getters
  string getVoice();
  string getName();
  //setters
  void setVoice(string);
  void setName(string);
  //printer
  void printInfo();

private:
  string name;
  string soundsLike;

};

#endif
