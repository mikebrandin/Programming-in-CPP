#ifndef TWEETPARSER_H
#define TWEETPARSER_H

using namespace std;

class TweetParser{
  private:
  string type;
  string detail;
  string loc;
  string lats;
  string lngs;
  string curline;
  float lat;
  float lng;
  string line;

  ifstream ifstr;
  stringstream sstr;


  public:
  TweetParser(const char* file); //constructor
  ~TweetParser(){}; //destructor

};

#endif
