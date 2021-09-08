#ifndef PGM_H
#define PGM_H

class ppm_t;

class pgm_t{
public:
  //big three: constructor, destructor, copy constructor
  pgm_t();
  pgm_t(const char* file);//constructor(overloaded)
  ~pgm_t();//destructor
  pgm_t(const pgm_t&);//copy construcor

  pgm_t(const ppm_t&);//**ppm to pgm conversion copy constructor**

  //overloaded operators
  pgm_t& operator= (const pgm_t& rhs);//copy assignment= operator
  char& operator[] (int i);//access img data at specifed location operator
  //getters
  int getPtype() const;
  int getW() const;
  int getH() const;
  int getBpp() const;
  int getMax() const;
  std::string getName() const;
  float* getGpix() const;
  char* getImg() const;
  //setters
  void setPtype(int);
  void setW(int);
  void setH(int);
  void setBpp(int);
  void setMax(int);
  void setName(std::string);
  void setImg(float*);
  void setGpix(float*);
  //friends
  friend std::istream& operator>>(std::istream& s, pgm_t& rhs);
  friend std::ostream& operator<<(std::ostream& s, pgm_t& rhs);
  friend std::istream& operator>>(std::istream& s, pgm_t* rhs);
  friend std::ostream& operator<<(std::ostream& s, pgm_t* rhs);

protected:
  int ptype; // magic number (int part of 'P5' or 'P6')
  int w,h; // width, height
  int bpp; // bytes per pixel (1 or 3)
  int max; // max color (usually 255)
  std::string name; // file name
  char* img; //bytes that are read in converted from float
  float* gpix; //float value read in by ifs.read
};

#endif
