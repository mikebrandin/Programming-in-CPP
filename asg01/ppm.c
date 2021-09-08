#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"

//allocate function
PPM *ppm_alloc(int r, int c){
  PPM *img = NULL;

  img = (PPM*)malloc(sizeof(PPM));
  img->ptype = 6;//initialize all struct members
  img->w = r;
  img->h = c;
  img->bpp = 3;
  img->max = 255;
  img->name = NULL;

//alocate space for rpix
  if(!(img->rpix = (float *)malloc(r*c*sizeof(float)))){
    fprintf(stderr, "out of memory\n");
    return NULL;
  }
  //alocate space for gpix
  if(!(img->gpix = (float *)malloc(r*c*sizeof(float)))){
    fprintf(stderr, "out of memory\n");
    return NULL;
  }
  //alocate space for bpix
  if(!(img->bpix = (float *)malloc(r*c*sizeof(float)))){
    fprintf(stderr, "out of memory\n");
    return NULL;
  }

  return img;
}

//free function
void ppm_free(PPM **img){

  if (*img){
    if((*img)->name){
      free((*img)->name);
    }
  if ((*img)->rpix) {
    free((*img)->rpix);
  }
  if ((*img)->gpix){
    free((*img)->gpix);
  }
  if ((*img)->bpix){
    free((*img)->bpix);
  }

  free(*img);
  }
  (*img) = NULL;

}

//read function
PPM *ppm_read(const char *file){
         //pixel* RGB;
    char buffer[10];
    PPM *img = NULL;
    int com;
    int max;
    int r = 0;
    int c = 0;
    unsigned char byte;

    //open file and read in binary mode
    FILE *fp = fopen(file, "rb");

    if (!fp) {//if file pointer is NULL display error
        fprintf(stderr, "Unable to open file '%s'\n", file);
        return NULL;
    }

    //scan file for the magic number
    if (!fgets(buffer, sizeof(buffer), fp)) {
      fprintf(stderr, "Invalid image format (must be 'P6')\n");
      return NULL;
    }

    //check if magic number matches P6 type
    if (buffer[0] != 'P' && buffer[1] != '6') {
      fprintf(stderr, "Invalid image format (must be 'P6')\n");
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
         fprintf(stderr, "Invalid image size\n");
         return NULL;
    }


    //scan file for max rgb value
    if (fscanf(fp, "%d", &max) != 1) {
         fprintf(stderr, "Invalid max rgb value\n");
         return NULL;
    }

    //check max rgb value
    if (max != 255) {
         fprintf(stderr, "Invalid max rgb value\n");
         return NULL;
    }

    //call allocation function to initialize img struct pointer and alloc memory
    img = ppm_alloc(r, c);
    img->name = (char*)malloc(sizeof(char)*strlen(file));//allocate memory for char pointer name member
    strcpy(img->name, file);//copy name from file to name struct member


    if (!img) {//test if memory allocation was successfull
        fprintf(stderr, "Invalid memory allocation to image.\n");
        return NULL;
    }

    //read pixel data from file
    for (int i = 0; i < img->w; i++){//loop through width
      for (int j = 0; j < img->h; j++){//loop through height
        //read in pixel data then calculate rgb value for three pixel arrays
        fread(&byte, sizeof(unsigned char), 1, fp);
        img->rpix[i*img->w + j] = (float)byte/img->max;

        fread(&byte, sizeof(unsigned char), 1, fp);
        img->gpix[i*img->w + j] = (float)byte/img->max;

        fread(&byte, sizeof(unsigned char), 1, fp);
        img->bpix[i*img->w + j] = (float)byte/img->max;
      }
    }

    fclose(fp);//close file pointer
    return img;
}

void ppm_write(PPM *img, const char *file){
    unsigned char byte;

    //open file for writing in binary mode
    FILE *fp = fopen(file, "wb");
    if (!fp) {//if file pointer is NULL display error
         fprintf(stderr, "Unable to open file '%s'\n", file);
    }

    //write the header file:
    //magic number/file format
    fprintf(fp, "P%d\n", img->ptype);

    //comment to state creator
    fprintf(fp, "# Created by Mike\n");

    //image width and height
    fprintf(fp, "%d %d\n",img->w,img->h);

    // rgb max color
    fprintf(fp, "%d\n", img->max);


    for (int i = 0; i < img->w; i++){//loop through width
      for (int j = 0; j < img->h; j++){//loop through height
        //calculate pixel data byte and write 3 bytes per pixel of the ppm file
        byte = (unsigned char)(img->gpix[i*img->w+j]*img->max);
        fwrite(&byte, sizeof(unsigned char), 1 , fp);

        byte = (unsigned char)(img->bpix[i*img->w+j]*img->max);
        fwrite(&byte, sizeof(unsigned char), 1 , fp);

        byte = (unsigned char)(img->rpix[i*img->w+j]*img->max);
        fwrite(&byte, sizeof(unsigned char), 1 , fp);
      }
    }
    fclose(fp);//close file pointer
}
