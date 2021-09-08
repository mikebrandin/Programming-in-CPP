#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

#include "pgm.h"
#include "ppm.h"

ppm_t::ppm_t(const char* file){

  if (!file);
  else{

    setName(file);//set name regardless of if file already exists

    std::ifstream ifs;
    //reading in image info //
    ifs.open(file,std::ios::in | std::ios::binary);
    if (!ifs) {//file is not in directory
      ifs.close();
    }
    else{
      if (ifs.good()){
        ifs >> this;//calls ifstream >> operator
      }
    ifs.close();
    }
  }

}

ppm_t::~ppm_t(){//destructor
  //delete allocated memory
if (rpix == nullptr){
  delete [] gpix;
}
if (gpix == nullptr){
  delete [] gpix;
}
if (bpix == nullptr){
  delete [] gpix;
}
};

ppm_t::ppm_t(const ppm_t& rhs){//copy constructor
  //delete allocated memory
  delete [] rpix;
  delete [] gpix;
  delete [] bpix;

  //copy everything except the file name
  this->setPtype(rhs.getPtype());
  this->setW(rhs.getW());
  this->setH(rhs.getH());
  this->setMax(rhs.getMax());
  this->setBpp(rhs.getBpp());
  this->setRpix(rhs.getRpix());
  this->setGpix(rhs.getGpix());
  this->setBpix(rhs.getBpix());

}

ppm_t& ppm_t::operator=(const ppm_t& rhs){
  if (this != &rhs){
    //delete allocated memory
    delete [] rpix;
    delete [] gpix;
    delete [] bpix;
    //copy everything except the file name
    this->setPtype(rhs.ptype);
    this->setW(rhs.w);
    this->setH(rhs.h);
    this->setMax(rhs.max);
    this->setBpp(rhs.bpp);
    this->setRpix(rhs.rpix);
    this->setGpix(rhs.gpix);
    this->setBpix(rhs.bpix);

  }
  return *this;
}

std::istream& operator>>(std::istream& s, ppm_t& rhs){//read in operator
  char buff[10];
  int maxx, r, c;
  char ch;
  s >> buff;
  //check if magic number matches P6 type
  if (buff[0] != 'P' || buff[1] != '6') {
      std::cout << "Invalid image format (must be 'P6')" << std::endl;
      exit(1);
  }
  else{
      rhs.setPtype(6);
      rhs.setBpp(3);
  }

  //ignore comments in header
  ch = '#';
  while (ch == '#'){
  while (s.get() != '\n');
      ch = s.get();
  }
  s.unget();

  s >> r >> c;//read in width and height

  rhs.setW(r);
  rhs.setH(c);

  rhs.rpix = new float [r * c];//allocate memory for float rpix array
  rhs.gpix = new float [r * c];//allocate memory for float gpix array
  rhs.bpix = new float [r * c];//allocate memory for float bpix array

  s >> maxx;//read in max value

  //check max color value
  if (maxx != 255) {
    std::cout << rhs.getName() << " does not have 8-bits components" << std::endl;
    exit(1);
  }
  else{
    rhs.setMax(maxx);
  }
  //rhs.byter = new char [r * c];
  char byte;
  for (int i = 0; i < rhs.getW(); i++){//loop through image to read in img bytes
    for (int j = 0; j < rhs.getH(); j++){//use these bytes to calculate color value
      // do 3 times for r g & b pixel
      s.read(&byte, 1);
      rhs.rpix[i*rhs.getH() + j] = float(byte) / (float)rhs.getMax();

      s.read(&byte, 1);
      rhs.getGpix()[i*rhs.getH() + j] = float(byte) / (float)rhs.getMax();

      s.read(&byte, 1);
      rhs.bpix[i*rhs.getH() + j] = float(byte) / (float)rhs.getMax();
    }
  }

  return s;
}

std::ostream& operator<<(std::ostream& s, ppm_t& rhs){//write operator
    //write header info:
  //magic number/file format
  s << 'P' << rhs.getPtype() << std::endl;
  //comment to state creator
  s << "# made my Mike Brandin" << std::endl;
  //image width and height
  s << rhs.getW()  << " " << rhs.getH() << std::endl;
  // rgb max color
  s << rhs.getMax() << std::endl;
  char byte;
  for (int i = 0; i < rhs.getW(); i++){//loop through entirety of image
    for (int j = 0; j < rhs.getH(); j++){//calculate img value and write to ostream
      // do 3 times for r g & b pixel
      byte = (unsigned char)(rhs.getGpix()[i*rhs.getH() + j] * float(rhs.getMax()));
      s.write(&byte, 1);

      byte = (unsigned char)(rhs.bpix[i*rhs.getH() + j] * float(rhs.getMax()));
      s.write(&byte, 1);

      byte = (unsigned char)(rhs.rpix[i*rhs.getH() + j] * float(rhs.getMax()));
      s.write(&byte, 1);

    }

  }
  return s;

}

std::istream& operator>>(std::istream& s, ppm_t* rhs){
  return (s >> (*rhs));//short hand for derefencing
}

std::ostream& operator<<(std::ostream& s, ppm_t* rhs){
  return (s << (*rhs));//short hand for derefencing
}

float* ppm_t::getBpix() const{
  return bpix;
}

float* ppm_t::getRpix() const{
  return rpix;
}

void ppm_t::setBpix(float* a){
  if(!bpix){
    bpix = new float [getW() * getH()];//allocate memory
  }
  for (int i = 0; i < getW(); i++){//loop through and read in float blue values
    for (int j = 0; j < getH(); j++){
      bpix[i*getH() + j] = a[i*getH() + j];
    }
  }
}

void ppm_t::setRpix(float* a){
  if(!rpix){
    rpix = new float [getW() * getH()];//allocate memory
  }

  for (int i = 0; i < getW(); i++){//loop through and read in float red values
    for (int j = 0; j < getH(); j++){
      rpix[i*getH() + j] = a[i*getH() + j];
    }
  }
}
