#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <iomanip>

#include "tweetParser.h"

using namespace std;

TweetParser::TweetParser(const char* file){
  ifstr.open(file);
  sstr.str("");

  getline(ifstr, type, ';');
  sstr << type;
  getline(sstr, line, 'p');
  getline(sstr, type, ';');
  sstr.clear();

  for (unsigned int i = 0; i < type.length(); i++){
    type[i] = toupper(type[i]);
  }
  cout << "Type:\t\t" << setw(6) << type << endl;

  getline(ifstr, detail, ';');
  sstr << detail;
  getline(sstr, line, 't');
  getline(sstr, detail, ';');
  sstr.clear();
  cout << "Detail:\t\t" << setw(5) << detail << endl;

  getline(ifstr, loc, ';');
  sstr << loc;
  getline(sstr, line, 'c');
  getline(sstr, loc, ';');
  sstr.clear();
  cout << "Location:\t" << setw(5) << loc << endl;

  getline(ifstr, lats, ';');
  sstr << lats;
  getline(sstr, line, 't');
  sstr >> lat;
  cout << "Latitude:\t " << setw(6) << lat << endl;
  sstr.clear();

  getline(ifstr, lngs, ';');
  sstr << lngs;
  getline(sstr, line, 'g');
  sstr >> lng;
  cout << "Longitude:\t " << setw(6) << lng << endl << endl;
  sstr.clear();


  while(getline(ifstr, curline, '\n')){
    getline(ifstr, type, ';');
    sstr << type;
    getline(sstr, line, 'p');
    getline(sstr, type, ';');
    sstr.clear();

    for (unsigned int i = 0; i < type.length(); i++){
      type[i] = toupper(type[i]);
    }
    cout << "Type:\t\t" << setw(6) << type << endl;

    getline(ifstr, detail, ';');
    sstr << detail;
    getline(sstr, line, 't');
    getline(sstr, detail, ';');
    sstr.clear();
    cout << "Detail:\t\t" << setw(5) << detail << endl;

    getline(ifstr, loc, ';');
    sstr << loc;
    getline(sstr, line, 'c');
    getline(sstr, loc, ';');
    sstr.clear();
    cout << "Location:\t" << setw(5) << loc << endl;

    getline(ifstr, lats, ';');
    sstr << lats;
    getline(sstr, line, 't');
    sstr >> lat;
    cout << "Latitude:\t " << setw(6) << lat << endl;
    sstr.clear();

    getline(ifstr, lngs, ';');
    sstr << lngs;
    getline(sstr, line, 'g');
    sstr >> lng;
    cout << "Longitude:\t " << setw(6) << lng << endl << endl;
    sstr.clear();

  }
  ifstr.close();

};
