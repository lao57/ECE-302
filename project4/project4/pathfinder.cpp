#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"


//struct
struct loc{
  int row;
  int col;
};

//protos
loc starter(Image<Pixel>);




int main(int argc, char *argv[])
{
  //vars
 loc mouse;





  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image<Pixel> image = readFromFile(input_file);
  mouse = starter(image);


  // TODO
  Queue<loc, loc> frontier;
  Queue<loc, loc> explored;


  // Write solution image to file
  writeToFile(image, output_file);
  
}

loc starter(Image<Pixel> img)
{
    int height = img.height();
    int width = img.width();
    bool found = false;
    loc start;
    for(int row = 0; row < height; row++){
      for(int col = 0; col < width; col++){
        if(img(row, col) == RED){
          if (found == true){
            std::cout << "Error - two red pixels found" << std::endl;
            start.row = -1;
            start.col = -1;
            return start;
          }else{
            found = true;
            start.row = row;
            start.col = col;
          }
        }
      }
    }
    return start;
}
