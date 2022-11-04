/*
Author: Ashlee Tolentino
Course: CSCI-135
Instructor: Michael Zamansky
Assignment: Lab-cipher

This program uses the techniques we discussed in class to decode the parameter encrypted_string. That string will be text that has been encoded using Caesar cipher.
*/

#include <iostream>
#include <string>
#include <vector>
#include "funcs.h"
#include "caesar.h"

// This function decodes the encrypted string
std::string solve(std::string encrypted_string)
{
  double letter_frequency[] =
  {
    0.0768837, 0.0144405, 0.0266625, 0.0484597, 0.132462,
    0.0250848, 0.0172021, 0.0567935, 0.0706592, 0.00144261,
    0.00505776, 0.0365912, 0.0304586, 0.0700241, 0.0725846,
    0.0176274, 0.000931088, 0.0599891, 0.0608684, 0.087482,
    0.0299299, 0.0110093, 0.0220128, 0.00194839, 0.02278,
    0.000614978
  };
  
  std::vector<double> solved_frequency(26);

  double min_average = INT_MAX;
  double current_average = 0;
  int rotation = 0;
  for(int i = 0; i < 26; i++)
  {
    double total = 0;
    std::string message = encryptCaesar(encrypted_string, i);
    solved_frequency = solve_frequency(message);
    for(int i = 0; i < 26; i++)
    {
      if(solved_frequency.at(i) != 0)
      {
	total += abs(letter_frequency[i] - solved_frequency.at(i));
      }
    }
    current_average = total/26;
    if(current_average < min_average)
    {
      min_average = current_average;
      rotation = i;
      //std::cout << rotation << std::endl;
    }
  }

  std::string result = encryptCaesar(encrypted_string, rotation);
  return result;
}


// This function solves for the frequency of each letter in a string
std::vector<double> solve_frequency(std::string encrypted_string)
{
  std::vector<double> solved_frequency(26); 
  
  int index = 0;
  int count = 0;
  for(int i = 0; i < encrypted_string.length(); i++)
  {
      char c = encrypted_string[i];
      if(isupper(c))
      {
	  count++;
	  index = (int)c - 65;
	  solved_frequency.at(index) += 1;
      }
      if(islower(c))
      {
	  count++;
	  index = (int)c - 97;
	  solved_frequency.at(index) += 1;
      }
  }

  for(int i = 0; i < 26; i++)
  {
    // solve for frequency by finding the average
    solved_frequency.at(i) = solved_frequency.at(i)/count;
  }
  return solved_frequency;
}
