#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pgm.h"

//allocate function
PGM *pgm_alloc(int r, int c){
  PGM *img = NULL;

  img = (PGM*)malloc(sizeof(PGM));
  img->ptype = 5;//initialize all struct members
  img->w = r;
  img->h = c;
  img->bpp = 1;
  img->max = 255;
  img->name = NULL;
  //alocate space for gpix
  if(!(img->gpix = (float *)malloc(r*c*sizeof(float)))) {
    fprintf(stderr, "out of memory\n");
    return NULL;
  }

  return img;
}

//free function
void pgm_free(PGM **img){
  if (*img){
    if((*img)->name){
      free((*img)->name);
    }

  if ((*img)->gpix){
    free((*img)->gpix);
  }


  free(*img);
  }
(*img) = NULL;

}
//read function
PGM *pgm_read(const char *file){
  //HAS A COMMENT ON THE FIRST LINE, NEEDS to be IGNORED
  PGM *img = NULL;
  //read in header
  char buff[10];

  unsigned char byte;
  int com;
  int max;
  int r = 0;
  int c = 0;
  //open PGM file for reading in binary
  FILE *fp = fopen(file, "rb");
  if (!fp) {
       fprintf(stderr, "Unable to open file '%s'\n", file);
       return NULL;
  }

  //scan file for the magic number
  if (!fgets(buff, sizeof(buff), fp)) {
    fprintf(stderr, "Invalid image format (must be 'P5')\n");
       return NULL;
  }

  //check if magic number matches P5 type
  if (buff[0] != 'P' || buff[1] != '5') {
  fprintf(stderr, "Invalid image format (must be 'P5')\n");
  return NULL;
  }


  //ignore comments in header
  com = getc(fp);
  while (com == '#') {
  while (getc(fp) != '\n') ;
    com = getc(fp);
  }

  ungetc(com, fp);
  //scan file for width and length of image
  if (fscanf(fp, "%d %d", &r, &c) != 2) {
  fprintf(stderr, "Invalid image size (error loading '%s')\n", file);
  return NULL;
  }

  //scan file for max gray value
  if (fscanf(fp, "%d", &max) != 1) {
  fprintf(stderr, "Invalid rgb component (error loading '%s')\n", file);
  return NULL;
  }

  //check max gray value
  if (max != 255) {
  fprintf(stderr, "'%s' does not have 8-bits components\n", file);
  return NULL;
  }

  //call allocation function to initialize img struct pointer and alloc memory
  img = pgm_alloc(r,c);
  img->name = (char*)malloc(sizeof(char)*strlen(file));//allocate memory for char pointer name member
  strcpy(img->name, file);//copy name from file to name struct member

  if (!img) {//test if memory allocation was successfull
       fprintf(stderr, "Unable to allocate memory\n");
       return NULL;
  }

  //read pixel data from file
  for (int i = 0; i < img->w; i++){//loop through width
    for (int j = 0; j < img->h; j++){//loop through height

      //read in pixel data then calculate gray value for one pixel array
      fread(&byte, sizeof(unsigned char), 1, fp);
      img->gpix[i*img->w + j] = (float)byte/(float)img->max;
    }
  }


  fclose(fp);//close file pointer

  return img;
}

void pgm_write(PGM *img, const char *file){

  //open file for writing in binary mode
  FILE *fp = fopen(file, "wb");

  unsigned char byte;

  if (!fp) {//if file pointer is NULL display error
       fprintf(stderr, "Unable to open file '%s'\n", file);
  }

  //write header info:
  //magic number/file format
  fprintf(fp, "P%d\n", img->ptype);
  //comment to state creator
  fprintf(fp, "# made my Mike Brandin\n");
  //image width and height
  fprintf(fp, "%d %d\n", img->w, img->h);
  // rgb max color
  fprintf(fp, "%d\n", img->max);


  for (int i = 0; i < img->w; i++){//loop through width
    for (int j = 0; j < img->h; j++){//loop through height
      //calculate pixel data byte and write 1 bytes per pixel of the ppm file
      byte = (unsigned char)(img->gpix[i*img->w+j]*(float)img->max);
      fwrite(&byte, sizeof(unsigned char), 1 , fp);

    }
  }

  fclose(fp);//close file pointer
}
