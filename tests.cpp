#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("Decrypt Cipher Case") {
  CHECK(solve("Rovvy, Gybvn!") == "Hello, World!");
  CHECK(solve("Bfd yt Lt!") == "Way to Go!");
}
