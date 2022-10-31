#include <iostream>
#include "funcs.h"

// add functions here
std::string solve(std::string encrypted_string){
  std::vector<double> eng_frequency =
    { //currently in percentage form, ordered alphabetically
      8.4966, 2.0720, 4.5388, 3.3844, 11.1607,
      1.8121, 2.4705, 3.0034, 7.5448, 0.1965,
      1.1016, 5.4893, 3.0129, 6.6544, 7.1635,
      3.1671, 0.1962, 7.5809, 5.7351, 6.9509,
      3.6308, 1.0074, 1.2899, 0.2902, 1.7779,
      0.2722
    };
  std::vector<double> encyrpted_frequency;
}

//cautionary function
double distance_formula(double x1, double x2, double y1, double y2){
  //distance formula
}

  /*vector notes
    vectorname.push_back(value); adds element into vector
    ^vectors memory will be modified to fit element

    to grab the value:
    vectorname[index position];

    vectorname.size() will return size of vector]

    to grab last element:
    vectorname[vectorname.size()-1]
    
