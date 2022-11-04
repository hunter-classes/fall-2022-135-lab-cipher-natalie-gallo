#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
std::string sample_text1 = "Already it was deep summer on roadhouse roofs and in front of wayside garages, where new red petrol-pumps sat out in pools of light, and when I reached my estate at West Egg I ran the car under its shed and sat for a while on an abandoned grass roller in the yard. The wind had blown off, leaving a loud, bright night, with wings beating in the trees and a persistent organ sound as the full bellows of the earth blew the frogs full of life. The silhouette of a moving cat wavered across the moonlight, and, turning my head to watch it, I saw that I was not alone—fifty feet away a figure had emerged from the shadow of my neighbour’s mansion and was standing with his hands in his pockets regarding the silver pepper of the stars. Something in his leisurely movements and the secure position of his feet upon the lawn suggested that it was Mr. Gatsby himself, come out to determine what share was his of our local heavens.";

std::string sample_text2 = "By seven o’clock the orchestra has arrived, no thin five-piece affair, but a whole pitful of oboes and trombones and saxophones and viols and cornets and piccolos, and low and high drums. The last swimmers have come in from the beach now and are dressing upstairs; the cars from New York are parked five deep in the drive, and already the halls and salons and verandas are gaudy with primary colours, and hair bobbed in strange new ways, and shawls beyond the dreams of Castile. The bar is in full swing, and floating rounds of cocktails permeate the garden outside, until the air is alive with chatter and laughter, and casual innuendo and introductions forgotten on the spot, and enthusiastic meetings between women who never knew each other’s names.";

std::string sample_text3 = "Tom was evidently perturbed at Daisy’s running around alone, for on the following Saturday night he came with her to Gatsby’s party. Perhaps his presence gave the evening its peculiar quality of oppressiveness—it stands out in my memory from Gatsby’s other parties that summer. There were the same people, or at least the same sort of people, the same profusion of champagne, the same many-coloured, many-keyed commotion, but I felt an unpleasantness in the air, a pervading harshness that hadn’t been there before. Or perhaps I had merely grown used to it, grown to accept West Egg as a world complete in itself, with its own standards and its own great figures, second to nothing because it had no consciousness of being so, and now I was looking at it again, through Daisy’s eyes. It is invariably saddening to look through new eyes at things upon which you have expended your own powers of adjustment.";

std::string encryption1 = encryptCaesar(sample_text1, 5);
std::string encryption2 = encryptCaesar(sample_text2, 10);
std::string encryption3 = encryptCaesar(sample_text3, 15);

TEST_CASE("Decrypt Cipher Case") {
  CHECK(solve(encryption1) == sample_text1);
  CHECK(solve(encryption2) == sample_text2);
  CHECK(solve(encryption3) == sample_text3);
}
