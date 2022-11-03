#include <iostream>
#include <climits>
#include <vector>
#include "funcs.h"

// add functions here
std::string solve(std::string encrypted_string){
  
  double eng_frequency[26] =
    { .084966, .020720, .045388, .033844, .111607, .018121, .024705, .030034, .075448, .001964, .011016, .054893, .030129, .066544, .071635, .031671, .001962, .075809, .057351, .069509, .036308, .010074, .012899, .002902, .017779, .002722
    };

  //26 spaces, default value of 0
  std::vector<double> encrypted_frequency;

  int rotation = 0;
  double current_smallest = INT_MAX;

  for (int i = 0; i < 26; i++){
    std::string message = encryptCaesar(encrypted_string, i);
    encrypted_frequency = make_frequency(message);

    double distance = 0;
    for (int j = 0; j < 26; j++){
      distance = distance + (encrypted_frequency.at(j) - eng_frequency[j]);
    }
    distance = distance/26; //avg distance in the vector
    if (distance < current_smallest){
      current_smallest = distance;
      rotation = i;
    }
  }

  std::string solved = encryptCaesar(encrypted_string, rotation);

  return solved;
}

std::vector<double> make_frequency(std::string encrypted_string){
  int index = 0;
  int letter_counter = 0;
  std::vector<double> frequency;

  for (int zero = 0; zero < 26; zero++){
    frequency.push_back(0);
  }
  
  //go through string and count how many times a letter appears
  for (int i = 0; i < encrypted_string.length(); i++){
    char c = encrypted_string[i];
    if (isupper(c)){
      index = (int)c - 65;
      frequency.at(index) = frequency.at(index) + 1;
      letter_counter = letter_counter + 1;
    } else if (islower(c)){
      index = (int)c - 97;
      frequency.at(index) = frequency.at(index) + 1;
      letter_counter = letter_counter + 1;
    }
  }
  //for every index in the vector, divide by number of letters to find frequency
  for (int j = 0; j < 26; j++){
    frequency.at(index) = frequency.at(index)/letter_counter;
  }

  return frequency;
}

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
