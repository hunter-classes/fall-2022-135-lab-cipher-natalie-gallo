#include <iostream>
#include <vector>
#include "funcs.h"

// add functions here
std::string solve(std::string encrypted_string){
  std::vector<double> eng_frequency(26) =
    { //ordered alphabetically
     .084966, .020720, .045388, .033844, .111607,
     .018121, .024705, .030034, .075448, .001964,
     .011016, .054893, .030129, .066544, .071635,
     .031671, .001962, .075809, .057351, .069509,
     .036308, .010074, .012899, .002902, .017779,
     .002722
    };

  //26 spaces, default value of 0
  std::vector<double> encyrpted_frequency(26);
  

}

//std::vector<double> letter_frequency(std::string rotated_string) {
  

//cautionary function, not sure if it will be used...
double distance_formula(double x1, double x2, double y1, double y2){
  //distance formula
  return sqrt(pow(x2 - x1, 2) + pow (y2 - y1, 2) * 1.0);
}

  /*vector notes
    vectorname.push_back(value); adds element into vector
    ^vectors memory will be modified to fit element

    to grab the value:
    vectorname[index position];

    vectorname.size() will return size of vector]

    to grab last element:
    vectorname[vectorname.size()-1]
  */

//CAESAR.CPP FUNCTIONS
    
char shiftChar(char c, int rshift){
  int c_shift = 0;
  int dec_c = int(c);
  int loop = rshift - 1;
  if (dec_c <= 90 && dec_c >= 90 - loop){ //loop through capitals
    rshift = rshift - (90 - dec_c);
    c_shift = 64 + rshift;
  } else if (dec_c <= 122 && dec_c >= 122 - loop) { //loop through lowercase
    rshift = rshift - (122 - dec_c);
    c_shift = 96 + rshift;
  } else if ((dec_c < 65) || (dec_c > 90 && dec_c < 97) || (dec_c > 122)){
    c_shift = dec_c;
  } else {
    c_shift = dec_c + rshift;
  }
  return (char)c_shift;
}

std::string encryptCaesar(std::string plaintext, int rshift){
  char c;
  std::string message;
  for (int i = 0; i < plaintext.length(); i++){
    c = plaintext[i]; //store character into char c
    message = message + shiftChar(c, rshift);
    //have a variable called message to store encrypted letters
    //do c plus whatever number character shift (refer to lab)
    //add that (not replace) to encrypted message variable
  }
  return message;
}
