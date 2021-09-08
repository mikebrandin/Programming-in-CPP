#ifndef PGM_H
#define PGM_H

typedef struct image{
  int ptype; // magic number (int part of 'P5' or 'P6')
  int w,h; // width, height
  int bpp; // bytes per pixel (1 or 3)
  int max; // max color (usually 255)
  char *name; // file name
  float* gpix;

}PGM;

//function prototypes for allocating, freeing, reading, and writing image data
PGM *pgm_alloc(int r, int c);
void pgm_free(PGM **img);

PGM *pgm_read(const char *file);
void pgm_write(PGM *img, const char *file);


#endif
