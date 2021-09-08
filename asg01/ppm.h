#ifndef PPM_H
#define PPM_H

typedef struct PPM_struct{
  int ptype; // magic number (int part of 'P5' or ' ')
  int w,h; // width, height
  int bpp; // bytes per pixel (1 or 3)
  int max; // max color (usually 255)
  char *name; // file name
  float *rpix;
  float *gpix;
  float *bpix;
}PPM;

//function prototypes for allocating, freeing, reading, and writing image data
PPM *ppm_alloc(int r, int c);
void ppm_free(PPM **img);

PPM *ppm_read(const char *file);
void ppm_write(PPM *img, const char *file);

#endif
