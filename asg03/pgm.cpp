#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>

#include "pgm.h"
#include "ppm.h"

class ppm_t;


pgm_t::pgm_t(){}


pgm_t::pgm_t(const char* file){

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

pgm_t::~pgm_t(){//destructor
  //delete allocated memory
if (img == nullptr){
  delete [] img;
}
if (gpix == nullptr){
  delete [] gpix;
}
};

pgm_t::pgm_t(const pgm_t& rhs){//copy constructor
  delete [] img;
  delete [] gpix;

  //copy everything except the file name
  this->setPtype(rhs.ptype);
  this->setW(rhs.w);
  this->setH(rhs.h);
  this->setMax(rhs.max);
  this->setBpp(rhs.bpp);
  this->setGpix(rhs.gpix);
  this->setImg(rhs.gpix);

}

pgm_t::pgm_t(const ppm_t& a){//ppm to pgm conversion copy constructor
  delete [] img;
  delete [] gpix;

  std::string tempname = a.name;

  unsigned int pos = tempname.find(".ppm");
  if (pos != std::string::npos){//change file ending to .pgm
    tempname = tempname.replace(pos, 4, ".pgm");
  }

  float* result = new float [a.getW() * a.getH()];
  for (int i = 0; i < a.getW(); i++){//loop through pixel arrays
    for (int j = 0; j < a.getH(); j++){//create gray value w/ weighted avg
      result[i*a.getH() + j] = (0.07 * a.getRpix()[i*a.getH() + j]) + (0.21 * a.getGpix()[i*a.getH() + j]) + (0.72 * a.getBpix()[i*a.getH() + j]);
    }
  }

  this->setPtype(5);//set to P5 type
  this->setW(a.w);
  this->setH(a.h);
  this->setMax(a.max);
  this->setBpp(1);//set 1 byte per pixel
  this->setGpix(result);
  this->setImg(result);
}

pgm_t& pgm_t::operator=(const pgm_t& rhs){
  if (this != &rhs){
    //delete allocated memory
    delete [] img;
    delete [] gpix;
    //copy everything except the file name
    this->setPtype(rhs.ptype);
    this->setW(rhs.w);
    this->setH(rhs.h);
    this->setMax(rhs.max);
    this->setBpp(rhs.bpp);
    this->setGpix(rhs.gpix);
    this->setImg(rhs.gpix);
  }
  return *this;
}

char& pgm_t::operator[] (int i){
  return img[i];//short hand method for retrieving pixel char value
}

std::istream& operator>>(std::istream& s, pgm_t& rhs){//read in operator
  char buff[10];
  int maxx, r, c;
  char ch;
  s >> buff;
  //check if magic number matches P5 type
  if (buff[0] != 'P' || buff[1] != '5') {
      std::cout << "Invalid image format (must be 'P5')" << std::endl;
      exit(1);
  }
  else{
      rhs.setPtype(5);
      rhs.setBpp(1);
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

  rhs.gpix = new float [r * c];//allocate memory for float gpix array

  s >> maxx;//read in max value

  //check max gray value
  if (maxx != 255) {
    std::cout << rhs.name << " does not have 8-bits components" << std::endl;
    exit(1);
  }
  else{
    rhs.setMax(maxx);
  }
  rhs.img = new char [r * c];

  for (int i = 0; i < rhs.w; i++){//loop through image to read in img bytes
    for (int j = 0; j < rhs.h; j++){//use these bytes to calculate gray value
      s.read(&rhs[i*rhs.h + j], 1);
      rhs.gpix[i*rhs.h + j] = float(rhs[i*rhs.h + j]) / (float)rhs.max;
    }
  }

  return s;
}

std::ostream& operator<<(std::ostream& s, pgm_t& rhs){//write operator
    //write header info:
  //magic number/file format
  s << 'P' << rhs.ptype << std::endl;
  //comment to state creator
  s << "# made my Mike Brandin" << std::endl;
  //image width and height
  s << rhs.w  << " " << rhs.h << std::endl;
  // rgb max color
  s << rhs.max << std::endl;

  for (int i = 0; i < rhs.w; i++){//loop through entirety of image
    for (int j = 0; j < rhs.h; j++){//calculate img value and write to ostream
      rhs[i*rhs.h + j] = (unsigned char)(rhs.gpix[i*rhs.h + j] * float(rhs.max));
      s.write(&rhs[i*rhs.h + j], 1);
    }

  }
  return s;

}

std::istream& operator>>(std::istream& s, pgm_t* rhs){
  return (s >> (*rhs));//short hand for derefencing
}

std::ostream& operator<<(std::ostream& s, pgm_t* rhs){
  return (s << (*rhs));//short hand for derefencing
}
//getters
int pgm_t::getPtype() const{
  return ptype;
}
int pgm_t::getW() const{
  return w;
}
int pgm_t::getH() const{
  return h;
}
int pgm_t::getBpp() const{
  return bpp;
}
int pgm_t::getMax() const{
  return max;
}
std::string pgm_t::getName() const{
  return name;
}
char* pgm_t::getImg() const{
  return img;
}
float* pgm_t::getGpix() const{
  return gpix;
}
//setters
void pgm_t::setPtype(int a){
  ptype = a;
}
void pgm_t::setW(int a){
  w = a;
}
void pgm_t::setH(int a){
  h = a;
}
void pgm_t::setBpp(int a){
  bpp = a;
}
void pgm_t::setMax(int a){
  max = a;
}
void pgm_t::setName(std::string a){
  name = a;
}
void pgm_t::setImg(float* a){
  img = new char [getW() * getH()];//allocate memory

  for (int i = 0; i < getW(); i++){//loop through and read in img bytes
    for (int j = 0; j < getH(); j++){
      img[i*getH() + j] = a[i*getH() + j] / (float)getMax();
    }
  }
}
void pgm_t::setGpix(float* a){
  gpix = new float [getW() * getH()];//allocate memory

  for (int i = 0; i < getW(); i++){//loop through and read in float gray values
    for (int j = 0; j < getH(); j++){
      gpix[i*getH() + j] = a[i*getH() + j];
    }
  }
}
