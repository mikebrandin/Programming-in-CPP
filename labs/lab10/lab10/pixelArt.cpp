#include <fstream>
#include <vector>
#include <string>
#include "pixelArt.h"

void pixelArt::readArts(const char* fileName)//read in file info
{
  ifstream fp; //create a input stream filepointer
  fp.open(fileName); //open file passed thru parameter
  string line; //temp variable
  while(getline(fp, line)){//while !end of file
    vector<int>row;
    for (unsigned int i = 0; i < line.length(); i++){//scan characters thru end of line

          row.push_back(line[i]-48);//convert char to int and add to end of row

    }

    pixels.push_back(row);//add rows to columns
  }

  fp.close();//close the file
}

pixelArt::pixelArt(int iw, int ih):w(iw),h(ih)//constructor
{
  w = iw;
  h = ih;

}

int pixelArt::getPixel(int i, int j)
{
  return pixels[i][j];
}

int pixelArt::getW() const
{
  return w;
}

int pixelArt::getH() const
{
  return h;
}


pixelArt pixelArt::operator + (int num)//add pixel values with integer
{
  pixelArt result(w, h);//construct temp pixel art class
  for (int i = 0; i < h; i++){//loop through height
    vector<int>vec;
    result.pixels.push_back(vec);//push back vector of intgers before rows aka newline
    for (int j = 0; j < w; j++){//loop through width
      result.pixels[i].push_back(getPixel(i, j) + num);//add num to all pixel value and push to back of temp variable rows
    }
  }

  return result; //return temp pixelart variable
}

pixelArt pixelArt::operator - (int num)//subtract pixel values with integer
{
  pixelArt result(w, h);
  for (int i = 0; i < h; i++){
    vector<int>vec;
    result.pixels.push_back(vec);
    for (int j = 0; j < w; j++){
      result.pixels[i].push_back(getPixel(i, j) - num);
    }
  }

  return result;
}

pixelArt pixelArt::operator + (const pixelArt& pa)//add pixel art classes together
{
  pixelArt result(w, h);

  for (int i = 0; i < h; i++){
    vector<int>vec;
    result.pixels.push_back(vec);
    for (int j = 0; j < w; j++){
      result.pixels[i].push_back(getPixel(i, j) + pa.pixels[i][j]);
    }
  }

  return result;
}

ostream& operator<<(ostream& os, const pixelArt& pa)//output pixel art info
{

  for (int i = 0; i < pa.getH(); i++){//loop through height
    for (int j = 0; j < pa.getW(); j++){//loop through 1st width quadrant
      if(pa.pixels[i][j] == 9){//replace 9s with spaces
        cout << " ";
      }
      else{
        cout << pa.pixels[i][j];
      }
    }
    cout << endl;
  }
  return os;//return ostream

}
