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

int main()
{
  std::string input = "What if a writer or novelist decided to write a 300-page book with no breaks in the text for new ideas, new chapters, or even character dialogue? It would be so overwhelming that the reader would probably take one look and close the book forever. When writing is divided up into manageable parts that are cohesive, it's much easier for the reader to take in and process. A paragraph is a distinct segment of writing, often includes more than one sentence, and is separated from other paragraphs and text by a space. Paragraphs break up text into manageable chunks that are easily read and visually make it more appealing and less daunting. The word paragraph comes from the Latin word paragraphos, which is roughly translated to mean a short-stroke marking a break in sense. The term graph is Latin for writing. There is often some confusion about what the difference is between a paragraph and an essay. The best way to understand the difference is to think of the essay as a bigger version of a paragraph. A paragraph is made up of a topic sentence, supporting sentences, and a concluding sentence. An essay has all the same parts; only instead of sentences, an essay is made up of paragraphs.";

  std::vector<double> solved_frequency(26);
  solved_frequency = solve_frequency(input);

  std::string encrypted_string = encryptCaesar(input, 10);

  std::string decrypted_string = solve(encrypted_string);
  std::cout << decrypted_string << std::endl;  
  
  return 0;
}
