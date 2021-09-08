#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pgm.h"//include header file

int main(int argc, char** argv){
  PGM* img;

  img = pgm_read("mandrill.pgm");//call read and return value to image pointer
  pgm_write(img,"copy.pgm");//call write to create a copy of read in image

  pgm_free(&img);//free image pointer and all data members

return 0;
}
