#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

//struct
struct loc{
  int row;
  int col;

  bool operator==(loc other){
    if (row == other.row && col == other.col){
      return true;
    }else{
      return false;
    }
  }
};

//protos
loc starter(Image<Pixel>, List<loc>&);




int main(int argc, char *argv[])
{
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

  //vars
 loc start, goal;
 List<loc> goals;
 Queue<loc, List<loc>> path;
 List<loc> visited;
 int width = image.width(), height = image.height();
 List<loc> parent;
 for(int i = 0; i < height; i++){
  for(int j = 0; j < width; j++){
    parent.insert(i*width+j, {-1,-1});
  }
 }
 bool found = false;






  start = starter(image, goals);

  //case where we start on end point
  if(goals.contains(start)){
//put in what to do if goal is start
  }else if(start.row == -1){
    //something went wrong
  }else{
    path.enqueue(start);
    while(!path.isEmpty()){
      loc mouse = path.peekFront();
      path.dequeue();
      visited.insert(0, mouse);

      for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
          if(r != 0 && c != 0){
          }else{
            loc next;
            next.row = mouse.row + r;
            next.col = mouse.col + c;

            if(image(next.row, next.col) != BLACK && next.row >= 0 && next.col >= 0  && next.row < height && next.col < width && !visited.contains(next)){
              parent.setEntry(next.row*width+next.col, mouse);
              if(goals.contains(next)){
                found = true;
                goal = next;
                break;
              }
              visited.insert(0,next);
              path.enqueue(next);

            }
          }
        }
      }


    }
  }
  if(found){
    std::cout << "Soultion Found" << std::endl;
    while(!(goal == start)){
      int r = goal.row, c = goal.col;
      image(r,c) = GREEN;
      goal = parent.getEntry(r*width + c);
    }
  }else{
    std::cout << "No Soultion Found" << std::endl;
  }


  // TODO
  


  // Write solution image to file
  writeToFile(image, output_file);
  return EXIT_SUCCESS;
  
}

loc starter(Image<Pixel> img, List<loc>& goals)
{
    int height = img.height();
    int width = img.width();
    bool found = false;
    loc start;
    for(int row = 0; row < height; row++){
      for(int col = 0; col < width; col++){
        if(img(row, col) == RED){
          if(row == 0 || col == 0 || row == height - 1 || col == width - 1){
            if (img(row, col) != BLACK){
              loc adder;
              adder.row = row;
              adder.col = col;
              goals.insert(0, adder);
            }
          }
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