#ifndef PPM_H
#define PPM_H

class ppm_t : public pgm_t{//inherit from derived class, pgm_t
public:
  //big three: constructor, destructor, copy constructor
  ppm_t(const char* file);//constructor(overloaded)
  ~ppm_t();//destructor
  ppm_t(const ppm_t& rhs);//copy constructor

  //overloaded operators
  ppm_t& operator= (const ppm_t& rhs);//copy assignment= operator
  //char& operator[] (int i);//access img data at specifed location operator
  //getters
  float* getRpix() const;
  float* getBpix() const;

  //setters
  void setRpix(float*);
  void setBpix(float*);
  //void allocGpix();

  //friends
  friend std::istream& operator>>(std::istream& s, ppm_t& rhs);
  friend std::ostream& operator<<(std::ostream& s, ppm_t& rhs);
  friend std::istream& operator>>(std::istream& s, ppm_t* rhs);
  friend std::ostream& operator<<(std::ostream& s, ppm_t* rhs);

private:
  float* rpix; //red float value read in by ifs.read
  float* bpix; //blue float value read in by ifs.read
};

#endif
