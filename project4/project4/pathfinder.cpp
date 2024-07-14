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
  Image<Pixel> image;
  try {
        image = readFromFile(input_file);
        
    } catch (const std::runtime_error &e) {
        std::cout << "Error - Image:Runtime error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

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
 int found = 0;






  start = starter(image, goals);

  //case where we start on end point
  if(goals.contains(start)){
    found = 2;
//put in what to do if goal is start
  }
  else if(goals.isEmpty()){
     found = -3;
  }
  else if(start.row == -1){
    std::cout << "Error - something went wrong in starter" << std::endl;
    found = -1;
    //something went wrong
  }else if(start.row == -2){
    std::cout << "Error - NOn-standard color found" << std::endl;
    found = -1;
    //something went wrong
    }else{
    path.enqueue(start);
    while(!path.isEmpty() && found == 0){
      loc mouse = path.peekFront();
      path.dequeue();
      visited.insert(0, mouse);
      for(int t = 0; t < 4; t++){
        int r, c;
        if(t == 0){
          r = -1, c = 0;
        }else if(t == 1){
          r = 1, c = 0;
        }else if(t == 2){
          r = 0, c = -1;
        }else{
          r = 0, c = 1;
        }
            loc next;
            next.row = mouse.row + r;
            next.col = mouse.col + c;

            if(image(next.row, next.col) != BLACK && next.row >= 0 && next.col >= 0  && next.row < height && next.col < width && !visited.contains(next)){
              parent.setEntry(next.row*width+next.col, mouse);
              if(next.row == height-1 || next.col == width -1 || next.col == 0 || next.row == 0){
                found = 1;
                goal = next;
                r = 5;
                c = 5;
                break;
              }
              visited.insert(0,next);
              path.enqueue(next);

            }
      }
    }
  }
  if(found == 1){
    std::cout << "Soultion Found" << std::endl;
    //while(!(goal == start)){
      int r = goal.row, c = goal.col;
      image(r,c) = GREEN;
      //goal = parent.getEntry(r*width + c);
    //}
  }else if(found == 2){
    int r = start.row, c = start.col;
    image(r,c) = GREEN;
    std::cout << "Soultion Found" << std::endl;
  }else if(found == -1){
    return EXIT_FAILURE;
  }else{
    std::cout << "No Soultion Found" << std::endl;
  }


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
        if (img(row, col) != RED && img(row, col) != WHITE && img(row, col) != BLACK){
          return {-2,-2};
        }
        if(row == 0 || col == 0 || row == height - 1 || col == width - 1){
            if (img(row, col) == WHITE){
              loc adder;
              adder.row = row;
              adder.col = col;
              goals.insert(0, adder);
            }
          }
        if(img(row, col) == RED){
          if(row == 0 || col == 0 || row == height - 1 || col == width - 1){
              loc adder;
              adder.row = row;
              adder.col = col;
              goals.insert(0, adder);
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