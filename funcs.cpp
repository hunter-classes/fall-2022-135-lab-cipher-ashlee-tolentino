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

//std::vector<double> solve_frequency(std::string);

// This function decodes the encrypted string
std::string solve(std::string encrypted_string)
{
  /*
  std::vector<double> letter_frequency(26);
  letter_frequency = solve_frequency("It is important to note that a paragraph does not have a minimum or maximum number of sentences that it must have to fit the definition of a paragraph. Some writers will opt to use very short paragraphs, while others will include dozens of sentences in their paragraphs. It is also important to know that most writers separate lines of dialogue into paragraphs, so if a character only speaks a single line, it will be its own paragraph. Keeping that in mind, there is a general agreement on the format of a standard paragraph, which especially applies to informational and argumentative or persuasive writing. A paragraph should be divided into three distinct sections that each serve a purpose to the paragraph as a whole.");
  */
  
  double letter_frequency[] =
  {
    .084966, .020720, .045388, .033844, .111607,
    .018121, .024705, .030034, .075448, .001964,
    .011016, .054893, .030129, .066544, .071635,
    .031671, .001962, .075809, .057351, .069509,
    .036308, .010074, .012899, .002902, .017779,
    .002722
  };
  

  std::vector<double> solved_frequency(26);

  double min_average = INT_MAX;
  //double total = 0;
  double current_average = 0;
  int rotation = 0;
  for(int i = 0; i < 26; i++)
  {
    //int present_letters = 0;
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
    //std::cout << current_average << std::endl;
    if(current_average < min_average)
    {
      min_average = current_average;
      rotation = i;
      std::cout << rotation << std::endl;
    }
  }

  std::string result = encryptCaesar(encrypted_string, rotation);
  return result;
  
  
  /*
  current_average = total/26;
  if(current_average < min_average)
  {
    min_average = current_average;
  }
  */
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
