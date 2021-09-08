#include <iostream>
#include <omp.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv){
  //declare and initial height and width values
  int h = 480, w = 640;
  //declare rgb float arrays
  float R[h][w];
  float G[h][w];
  float B[h][w];


  int tid = 0;//thread id
  int ncores = 0;//number of cores

  // figure out how many threads we have available
  #pragma omp parallel private(tid)
  {
    if((tid = omp_get_thread_num()) == 0)
      ncores = omp_get_num_threads();//if no threads then set number of cores to 0 (aka error)
  }
  fprintf(stderr,"num cores: %d\n", ncores);//print number of cores


  // calculate chunk, splitting up work as evenly as possible
  int chunk;
  chunk = h/ncores; //print number of cores and height & equation to find chunks
  fprintf(stderr,"h: %d\n", h);
  fprintf(stderr,"chunk (%d/%d): %d\n", h, ncores, chunk);

  //communicate to omp that w&h and RGB are public while thread id is a private type
  #pragma omp parallel   \
    shared(w,h,R,G,B)   \
    private(tid)

    #pragma omp for schedule(static,chunk) nowait


  for (int y = h - 1; y >= 0; y--){
    for (int x = 0; x < w; x++){
      tid = omp_get_thread_num();//set the value to each thread id to its core #
      switch (tid){//change color based on what thread is being used
        //virtual comp has 8 cores
        case 0: // first core processing instructions
        R[y][x] = 0.0;
        G[y][x] = 1.0;//set pixel color data
        B[y][x] = 0.5;
        break;

        case 1:// second core processing instructions
        R[y][x] = 0.7;
        G[y][x] = 0.0;
        B[y][x] = 1.0;
        break;

        case 2:// third core processing instructions
        R[y][x] = 1.0;
        G[y][x] = 0.0;
        B[y][x] = 0.3;
        break;

        case 3:// fourth core processing instructions
        R[y][x] = 0.1;
        G[y][x] = 0.3;
        B[y][x] = 0.8;
        break;

        case 4:// fifth core processing instructions
        R[y][x] = 0.0;
        G[y][x] = 1.0;
        B[y][x] = 0.5;
        break;

        case 5:// sixth core processing instructions
        R[y][x] = 0.7;
        G[y][x] = 0.0;
        B[y][x] = 1.0;
        break;

        case 6:// seventh core processing instructions
        R[y][x] = 1.0;
        G[y][x] = 0.0;
        B[y][x] = 0.3;
        break;

        case 7:// eighth core processing instructions
        R[y][x] = 0.1;
        G[y][x] = 0.3;
        B[y][x] = 0.8;
        break;

      }

    }
  }

// open output file
FILE* out = fopen("color.ppm","w");
if(!out) {//if file is null print error
  printf("Error in opening output image\n");
  return 1;
}
//declare rgb unsigned char pixel data
unsigned char r, g, b;

// write output
fprintf(out,"P6\n%d %d\n255\n", w, h);//write header
for(int i = 0; i < h; i++) {
  for(int j = 0; j < w; j++) {
  //set pixel data
  r = (unsigned char)(R[i][j] * 255.0);
  g = (unsigned char)(G[i][j] * 255.0);
  b = (unsigned char)(B[i][j] * 255.0);
  //write pixel data to file to create image
  fwrite(&r, sizeof(unsigned char), 1, out);//red pixel
  fwrite(&g, sizeof(unsigned char),1,out);//green pixel
  fwrite(&b, sizeof(unsigned char),1,out);//blue pixel
  }
}

return 0;

}
