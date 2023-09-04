#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
  string filename;
  int width = 0;
  int height = 0;
  int targetWidth = 0;
  int targetHeight = 0;

  // Add code to validate input (Do in part 1)
  cout << "Input filename: ";
  cin >> filename;
  cout << "Input width: ";
  if(!(cin >> width))
  {
    cout << string{"Error: width is a non-integer value"};
    return 1;
  }
  cout << "Input height: ";
  if(!(cin >> height))
  {
    cout << string{"Error: height is a non-integer value"};
    return 1;
  }
  cout << "Input target target width: ";
  if(!(cin >> targetWidth))
  {
    cout << string{"Error: target width is a non-integer value"};
    return 1;
  }
  cout << "Input target height: ";
  if(!(cin >> targetHeight))
  {
    cout << string{"Error: target height is a non-integer value"};
    return 1;
  }
  if(width<1)
  {
    cout << string{"Error: width must be greater than 0. You entered "} << to_string(width);
    return 1;
  }
  else if (height<1)
  {
    cout << string{"Error: height must be greater than 0. You entered "} << to_string(height);
    return 1;
  }
  else if(targetWidth<1)
  {
    cout << string{"Error: target width must be greater than 0. You entered "} << to_string(targetWidth);
    return 1;
  }
  else if (targetHeight<1)
  {
    cout << string{"Error: target height must be greater than 0. You entered "} << to_string(targetHeight);
    return 1;
  }
  else if(targetWidth > width)
  {
    cout << string{"Error: targetWidth must be less than width,"} << "\n" << to_string(targetWidth) << string{" is greater than "} << to_string(width);
    return 1;
  }
  else if (targetHeight > height)
  {
    cout << string{"Error: targetHeight must be less than height,"} << "\n" << to_string(targetHeight) << string{" is greater than "} << to_string(height);
    return 1;
  }

  int originalWidth = width; // need to delete image array at end of program

  Pixel** image = createImage(width, height); // create array of size that we need
  if (image != nullptr) {
    if (loadImage(filename, image, width, height)) {
      cout << "Start carving..." << endl;


      // set up output filename
      stringstream ss;
      ss << "carved" << width << "X" << height << "." << filename;
      outputImage(ss.str().c_str(), image, width, height);
    }

    // call last to remove the memory from the heap
    deleteImage(image, originalWidth);
  }
  // else
  return 0;
}