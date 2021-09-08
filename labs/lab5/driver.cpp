/*
Mike Brandin
CPSC 1021
2/11/2020
*/


#include "car.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  Car Car1;

  string make;
  string model;
  int year;
  double price;

      ifstream in_file ("raw.data");
      ofstream out_file;
      out_file.open("formatted.data", std::ios_base::app);

    for (int i = 0; i < 5; i++){
      in_file >> year >> make >> model >> price;
      Car1.setYear(year);
      Car1.setMake(make);
      Car1.setModel(model);
      Car1.setPrice(price);
      if (i != 0){
        out_file << endl;
        out_file << setw(10) << "  Car " << i+1 << ":" << endl;

      }
      else{
        out_file << setw(10) << "  Car " << i+1 << ":" << endl;
      }
      Car1.printCarInfo();

    }

    in_file.close();
    //when done writing, close the file output fstream
    out_file.close();

return 0;
}
