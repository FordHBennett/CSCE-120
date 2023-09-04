
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  std::cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];

  bool fail = false;

  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];

    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }

  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // delete array of pointers
    return nullptr;
  }

  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
 std::cout<< "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
 std::cout<< "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

// int* createSeam(int length) {
//   return nullptr;
// }

// void deleteSeam(int* seam) {
// }

bool loadImage(string filename, Pixel** image, int width, int height)
{
  ifstream read_stream(filename);
  if(!(read_stream))
  {
    std::cout<< "Error: failed to open input file - " << filename;
    return false;
  }
  string line;

  if(getline(read_stream,line,'\n'))
  {
    string asldj = line.substr(0,2);
    if(!(line.substr(0,2) == string{"P3"} || line.substr(0,2) == string{"p3"}))
    {
      std::cout<< "Error: type is " << line.substr(0,2) << " instead of P3";
      return false;
    }
    else if(line.substr(0,1)==string{"-"})
    {
      std::cout<< "Error: read non-integer value";
      return false;
    }
  }
  else
  {
    std::cout<< "Error: read non-integer value";
    return false;
  }

  if(getline(read_stream,line,' '))
  {
    try
    {
      if(stoi(line) != width)
      {
        std::cout<< "Error: input width (" << width << ")" << " does not match value in file (" << line << ")";
        return false;
      }
    }
    catch(const std::exception& e)
    {
      std::cout<< "Error: read non-integer value";
      return false;
    }
  }
  else
  {
    std::cout<< "Error: read non-integer value";
    return false;
  }
  if(getline(read_stream,line,'\n'))
  {
    try
    {
      if(stoi(line) != height)
      {
        std::cout<< "Error: input height (" << height << ")" << " does not match value in file (" << line<< ")";
        return false;
      }
    }
    catch(const std::exception& e)
    {
      std::cout<< "Error: read non-integer value";
      return false;
    }
  }
  else
  {
    std::cout<< "Error: read non-integer value";
    return false;
  }
  // if(getline(read_stream,line,'\n'))
  // {
  //   try
  //     {

  //       if((stoi(line) > 255)||((stoi(line) < 0)))
  //       {
  //         std::cout<< "Error: invalid color value";
  //         return false;
  //       }
  //     }
  //     catch(const std::exception& e)
  //     {
  //       std::cout<< "Error: read non-integer value";
  //       return false;
  //     }
  //   }
  // else
  // {
  //   std::cout<< "Error: read non-integer value";
  //   return false;
  // }
  // int max_val;
  // max_val = stoi(line);


  //------------------------------------------------------------------------------------------
  ifstream rgb_stream(filename);
  string image_file = string{""};
  string hold;
  string pixel_line;
  int num_pix = 1;
  getline(rgb_stream,hold,'\n');
  getline(rgb_stream,hold,'\n');
  getline(rgb_stream,hold,'\n');
  while(getline(rgb_stream,pixel_line))
  {
    int line_length = pixel_line.size();
    pixel_line = pixel_line + ' ';
    for(int i = 0; i<line_length; i++)
    {
      if(pixel_line[0]== ' ')
      {
        pixel_line.erase(0,1);
        line_length--;
        i--;
      }
      else if((pixel_line[i] == ' ') && (pixel_line[i+1] == ' '))
      {
        pixel_line.erase(i,1);
        line_length--;
        i--;
      }
      else if (pixel_line[i] == '\r')
      {
        pixel_line.erase(i,1);
        line_length--;
        i--;
      }


    }
    image_file = image_file + pixel_line;
  }
  while(image_file[(image_file.size())-1]==' ')
  {
    image_file.erase(((image_file.size())-1),1);
  }

  for(size_t i = 0; i < image_file.size(); i++)
  {
    if(image_file[i]==' '){num_pix++;}
  }

  if(num_pix < (width*height*3))
  {
    cout << "Error: not enough color values";
    return false;
  }
  else if(num_pix > (width*height*3))
  {
    cout << "Error: too many color values";
    return false;
  }

//---------------------------------------------------------------------------------------------------------------
  int* rgb_arr{ new int[num_pix]{} };
  for(int i = 0; i<num_pix;i++)
  {
    try
    {
      int index_of_whitespace = image_file.find_first_of(' ');
      int color_of_pixel = stoi(image_file.substr(0,index_of_whitespace));
      image_file = image_file.substr((index_of_whitespace+1));
      if((color_of_pixel > 255)||(color_of_pixel < 0))
      {
        cout << "Error: invalid color value " << color_of_pixel;
        delete[] rgb_arr;
        return false;
      }
      else
      {
        rgb_arr[i] = color_of_pixel;
      }
    }
    catch(const std::exception& e)
    {
      cout << "Error: read non-integer value";
      delete[] rgb_arr;
      return false;
    }
  }

  int pixel_count = 0;
  for(int row = 0; row < height; row++)
  {
    for(int col = 0; col < width; col++)
    {
      for(int k = 0; k<3; k++)
      {
        if(k==0)
        {
          image[col][row].r = rgb_arr[pixel_count];
          pixel_count++;
        }
        else if (k==1)
        {
          image[col][row].g = rgb_arr[pixel_count];
          pixel_count++;
        }
        else
        {
          image[col][row].b = rgb_arr[pixel_count];
          pixel_count++;
        }
      }
    }
  }

  delete[] rgb_arr;
  return true;
}

bool outputImage(string filename, const Pixel*const* image, int width, int height) {
  ofstream output_file;
  output_file.open(filename);
  if (output_file.is_open())
  {
    output_file << "P3\n";
    output_file << width << " " << height << "\n";
    output_file << "255\n";
    for(int row = 0; row < height; row++)
    {
      for(int col = 0; col < width; col++)
      {
        for(int k = 0; k<3; k++)
        {
          if(k==0)
          {
            output_file << image[col][row].r<< " ";
          }
          else if (k==1)
          {
            output_file << image[col][row].g << " ";
          }
          else
          {
            output_file << image[col][row].b << " ";
          }
        }
      }
      output_file << '\n';
    }
  }
  else
  {
    cout << "Error: failed to open output file - " << filename;
    return false;
  }

  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height)
{
  int x_grad;
  int y_grad;
  cout << image[x][0].r << " " <<  image[x][0].g << " " << image[x][0].b << " " << '\n';
  cout << image[x][(width-1)].r << " " <<  image[x][(width-1)].g << " " << image[x][(width-1)].b << " " << '\n';
  if(width>2)
  {
    if((x>0)&&(x<(width-1)))
    {
      int r_x_grad = image[(x+1)][y].r - image[(x-1)][y].r;
      int g_x_grad = image[(x+1)][y].g - image[(x-1)][y].g;
      int b_x_grad = image[(x+1)][y].b - image[(x-1)][y].b;
      x_grad = ((r_x_grad*r_x_grad) +(g_x_grad*g_x_grad) + (b_x_grad*b_x_grad));
    }
    else if(x==(width-1))
    {
      int r_x_grad = image[0][y].r - image[(x-1)][y].r;
      int g_x_grad = image[0][y].g - image[(x-1)][y].g;
      int b_x_grad = image[0][y].b - image[(x-1)][y].b;
      x_grad = ((r_x_grad*r_x_grad) +(g_x_grad*g_x_grad) + (b_x_grad*b_x_grad));
    }
    else if(x==0)
    {
      int r_x_grad = image[1][y].r - image[(width-1)][y].r;
      int g_x_grad = image[1][y].g - image[(width-1)][y].g;
      int b_x_grad = image[1][y].b - image[(width-1)][y].b;
      x_grad = ((r_x_grad*r_x_grad) +(g_x_grad*g_x_grad) + (b_x_grad*b_x_grad));
    }
  }
  else
  {
    x_grad = 0;
  }


  if(height>2)
  {
    if((y>0)&&(y<(height-1)))
    {
      int r_y_grad = image[x][(y+1)].r - image[x][(y-1)].r;
      int g_y_grad = image[x][(y+1)].g - image[x][(y-1)].g;
      int b_y_grad = image[x][(y+1)].b - image[x][(y-1)].b;
      y_grad = ((r_y_grad*r_y_grad) +(g_y_grad*g_y_grad) + (b_y_grad*b_y_grad));
    }
    else if(y==(height-1))
    {
      int r_y_grad = image[x][0].r - image[x][(y-1)].r;
      int g_y_grad = image[x][0].g - image[x][(y-1)].g;
      int b_y_grad = image[x][0].b - image[x][(y-1)].b;
      y_grad = ((r_y_grad*r_y_grad) +(g_y_grad*g_y_grad) + (b_y_grad*b_y_grad));
    }
    else if(y==0)
    {
      int r_y_grad = image[x][1].r - image[x][(height-1)].r;
      int g_y_grad = image[x][1].g - image[x][(height-1)].g;
      int b_y_grad = image[x][1].b - image[x][(height-1)].b;
      y_grad = ((r_y_grad*r_y_grad) +(g_y_grad*g_y_grad) + (b_y_grad*b_y_grad));
    }
  }
  else
  {
    y_grad = 0;
  }

  int tot = x_grad+y_grad;
  return tot;
}


int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
  seam[0] = start_col;
  int total_energy = energy(image, start_col, 0, width, height);
  int col = start_col;
  int row = 0;
  while(((row+1)<height)&&(col<width))
  {
    int down_energy = energy(image,  col, (row+1), width, height);
    int right_energy;
    if(col==0){ right_energy = INT32_MAX;}
    else{ right_energy = energy(image, (col-1), (row+1), width, height);}
    int left_energy;
    if((col+1)<width){ left_energy=  energy(image, (col+1), (row+1), width, height);}
    else{left_energy=INT32_MAX;}

    if(((left_energy == down_energy)&&(right_energy>down_energy)) || ((right_energy == down_energy)&&(left_energy>down_energy)))
    {
      row++;
      total_energy += down_energy;
      seam[row] = col;
    }
    else if (((left_energy == right_energy)&&(down_energy>right_energy)) || ((right_energy == left_energy)&&(down_energy > left_energy)))
    {
      col++;
      row++;
      total_energy += right_energy;
      seam[row] = col;
    }
    else if ((left_energy < right_energy)&&(left_energy < down_energy))
    {
      col++;
      row++;
      total_energy += left_energy;
      seam[row] = col;
    }
    else if ((left_energy > right_energy)&&(right_energy < down_energy))
    {
      col--;
      row++;
      total_energy += right_energy;
      seam[row] = col;
    }
    else
    {
      row++;
      total_energy += down_energy;
      seam[row] = col;
    }
  }

  return total_energy;
}

// int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
//   return 0;
// }

int* findMinVerticalSeam(Pixel** image, int width, int height) {
  int* min_energy_seam = new int[height];
  min_energy_seam[0] = loadVerticalSeam(image, 0, width, height, min_energy_seam);
  int* min;

  for(int i = 1; i<width;i++)
  {
    min_energy_seam[i] = loadVerticalSeam(image, i, width, height, min_energy_seam);
    if(min_energy_seam[i]<min_energy_seam[i-1]){min = &(min_energy_seam[i]);}
  }
  //delete[] min_energy_seam;

  return min;
}

// int* findMinHorizontalSeam(Pixel** image, int width, int height) {
//   return nullptr;
// }

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
  for(int row = 0; row < height; row++)
  {
    for(int col = verticalSeam[row]; col < (width-1); col++)
    {
      image[col][row] = image[(col+1)][row];
    }
  }
}


void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    for(int col = 0; col < width; col++)
  {
    for(int row = horizontalSeam[col]; row < (height-1); row++)
    {
      image[col][row] = image[col][(row+1)];
    }
  }
}