#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  unsigned int length = 0;
  char *char_ptr =str;
  while(*char_ptr++){length++;}
  return length;
}

unsigned int find(char str[], char character) {
  // returns
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  unsigned int index = 0;
  unsigned int length_arr = length(str);
  for(;index<length_arr; index++)
  {
    if(str[index] == character){break;}
  }
  return index;
}

//bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
//  return true;
//}