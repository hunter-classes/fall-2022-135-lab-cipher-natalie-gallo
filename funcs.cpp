#include <iostream>
#include <climits>
#include <vector>
#include "funcs.h"

// add functions here
std::string solve(std::string encrypted_string){
  
  /* double eng_frequency[26] =
    { .084966, .020720, .045388, .033844, .111607, .018121, .024705, .030034, .075448, .001964, .011016, .054893, .030129, .066544, .071635, .031671, .001962, .075809, .057351, .069509, .036308, .010074, .012899, .002902, .017779, .002722
    };*/

  double eng_frequency[] =
  {
    0.0768837, 0.0144405, 0.0266625, 0.0484597, 0.132462,
    0.0250848, 0.0172021, 0.0567935, 0.0706592, 0.00144261,
    0.00505776, 0.0365912, 0.0304586, 0.0700241, 0.0725846,
    0.0176274, 0.000931088, 0.0599891, 0.0608684, 0.087482,
    0.0299299, 0.0110093, 0.0220128, 0.00194839, 0.02278,
    0.000614978
  };

  // 26 spaces, default value of 0
  std::vector<double> encrypted_frequency;

  int rotation = 0;
  double current_smallest = INT_MAX;
  int counter;

  for (int i = 1; i < 26; i++) {
    std::string message = encryptCaesar(encrypted_string, i);
    encrypted_frequency = make_frequency(message);
    double avg_distance = 0;
    double distance = 0;
    for (int j = 0; j < 26; j++) {
      if (encrypted_frequency.at(j) != 0) {
        distance = distance + (encrypted_frequency.at(j) - eng_frequency[j]);
        counter++;
      }
    }
    avg_distance = distance / counter; // avg distance in the vector
    //std::cout << avg_distance << " rotation " << i << std::endl;
    if (avg_distance < current_smallest) {
      current_smallest = avg_distance;
      rotation = i;
    }
  }

  /* if (rotation == 13){
    rotation = rotation + 3;
  }

  if (rotation == 15){
    rotation = rotation + 6;
    }*/

  std::string solved = encryptCaesar(encrypted_string, rotation);

  return solved;
}

std::vector<double> make_frequency(std::string encrypted_string){
  int index = 0;
  double letter_counter = 0;
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
    frequency.at(j) = frequency.at(j)/letter_counter;
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
  }
  return message;
}
