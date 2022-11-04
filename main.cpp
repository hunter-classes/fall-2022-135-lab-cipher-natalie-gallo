#include <iostream>
#include <climits>
#include <vector>
#include "funcs.h"

int main()
{
  std::cout << "Oh! Mr.Gatsby, \nHere's a excerpt from your story: \n\n";
  std::string sample_text = "Already it was deep summer on roadhouse roofs and in front of wayside garages, where new red petrol-pumps sat out in pools of light, and when I reached my estate at West Egg I ran the car under its shed and sat for a while on an abandoned grass roller in the yard. The wind had blown off, leaving a loud, bright night, with wings beating in the trees and a persistent organ sound as the full bellows of the earth blew the frogs full of life. The silhouette of a moving cat wavered across the moonlight, and, turning my head to watch it, I saw that I was not alone—fifty feet away a figure had emerged from the shadow of my neighbour’s mansion and was standing with his hands in his pockets regarding the silver pepper of the stars. Something in his leisurely movements and the secure position of his feet upon the lawn suggested that it was Mr. Gatsby himself, come out to determine what share was his of our local heavens.";

  std::string encryption = encryptCaesar(sample_text, 5);
  std::cout << encryption << std::endl << "\nOops wrong one-! \n\n";
  std::cout << solve(encryption) << std::endl << "\nThat's better! \n";
  return 0;
}
