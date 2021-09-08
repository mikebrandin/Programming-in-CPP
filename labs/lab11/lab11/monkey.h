#ifndef MONKEY_H
#define MONKEY_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Monkey : public Animal{
public:
  //constructor
  Monkey(string, string);
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
