/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab8

This program contains functions that...
*/

#include <iostream>
#include <string>
#include <vector>
#include "funcs.h"
#include "caesar.h"

int main()
{
  std::string input = "Hello, World!";

  std::vector<double> solved_frequency(26);
  solved_frequency = solve_frequency(input);

  /*
  for(int i = 0; i < 26; i++)
  {
    std::cout << solved_frequency.at(i) << std::endl;
  }
  */

  std::string encrypted_string = encryptCaesar(input, 10);
  //std::cout << encrypted_string << std::endl;
  

  std::string decrypted_string = solve(encrypted_string);
  std::cout << decrypted_string << std::endl;
  
  return 0;
}

//count spaces and then substract it from the length of sentence
