/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab-cipher

This program contains functions implementing Caesar cipher encryption.
*/

#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift) // rshift: 0 <= rshift <= 25
{
  char result = c;

  if(((int)c > 64 && (int)c < 91) || ((int)c > 96 && (int)c < 123))
  {
    result = c + rshift;
  }
  else
  {
    return result;
  }

  if(((int)c > 64 && (int)c < 91) && (int)c + rshift > 90)
  {
    result = ((c + rshift) - 90) + 64;
  }
  if(((int)c > 96 && (int)c < 123) && (int)c + rshift > 122)
  {
    result = ((c + rshift) - 122) + 96;
  }
  
  return result;
}

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift)
{
  std::string result = "";
  
  for(int i = 0; i < plaintext.length(); i++)
  {
    char letter = plaintext[i]; //converts substring into a char
    char c = shiftChar(letter, rshift);
    std::string s(1, c); //converts char into a string
    result += s;
  }
  
  return result;
}

