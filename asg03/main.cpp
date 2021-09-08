#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

#include "pgm.h"
#include "ppm.h"

int main(int argc, char* argv[]){

  ppm_t org("mandrill.ppm");

  pgm_t cpy(org);

  std::ofstream ofs;

  ofs.open("copy.pgm", std::ios::out|std::ios::binary);
  ofs << cpy;
  ofs.close();

  return 0;
}
