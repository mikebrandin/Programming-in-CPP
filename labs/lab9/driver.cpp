/*
Mike Brandin
03/13/2020
CPSC 1021
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <iomanip>

#include "tweetParser.h"

using namespace std;

int main (int argc, char** argv){

  if(argc != 2){
    cout << "Invalid: command line arguement" << endl;//if more or less than 2 arguemnts are passed
  }

  const char* filename = argv[1];

  TweetParser parse(filename);//call tweet parser constructor



return 0;
}
