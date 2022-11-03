#pragma once

std::string solve(std::string encrypted_string);
std::vector<double> make_frequency(std::string encrypted_string);
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
