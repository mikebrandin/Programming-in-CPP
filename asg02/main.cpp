#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>

#include "pgm.h"

int main(){
  pgm_t org("mandrill.pgm");
  pgm_t cpy("gray.pgm");

  std::ofstream ofs;

  ofs.open("copy.pgm", std::ios::out|std::ios::binary);
  ofs << org;
  ofs.close();

  cpy = org;
  //pgm_t test = org; // to test the copy constructor

  ofs.open(cpy.getName().c_str(), std::ios::out|std::ios::binary);
  ofs << cpy;
  ofs.close();

  return 0;
}
