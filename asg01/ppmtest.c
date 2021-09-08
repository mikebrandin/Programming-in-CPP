#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"//include header file

int main(int argc, char** argv){
  PPM* img;

  img = ppm_read("mandrill.ppm");//call read and return value to image pointer
  ppm_write(img,"copy.ppm");//call write to create a copy of read in image

  ppm_free(&img);//free image pointer and all data members

return 0;
}
