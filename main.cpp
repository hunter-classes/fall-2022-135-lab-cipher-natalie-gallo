#include <iostream>
#include <climits>
#include <vector>
#include "funcs.h"

int main()
{
  std::cout << "Oh! Rovvy, Gybvn! \nSorry I meant " << std::endl; 
  std::string solved = solve("Rovvy, Gybvn!");
  std::cout << solved << std::endl;
  return 0;
}
