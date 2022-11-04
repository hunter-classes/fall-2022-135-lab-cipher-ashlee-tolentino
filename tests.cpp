#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"

// add your tests here

TEST_CASE("shiftChar"){
  CHECK(shiftChar('W', 5) == 'B');
  CHECK(shiftChar('o', 10) == 'y');
  CHECK(shiftChar('!', 15) == '!');
}

TEST_CASE("Caesar Encryption"){
  CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
  CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
}

/*
TEST_CASE("Caesar Decryption"){
  CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
  CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
}
*/
