#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

struct State {
    int row;
    int col;
};

bool ValidColorCheck(const Pixel& pixel) {
  return pixel == BLACK || pixel == WHITE || pixel == RED;
}

bool ValidMove(const Image<Pixel>& image, State s) {
    return (image(s.row, s.col) == WHITE);
}

bool HasExplored(const List<State>& list, const State& s) {
    for (std::size_t i=0; i<list.getLength(); i++) {
        if (list.getEntry(i).row == s.row && list.getEntry(i).col == s.col) {
            return true;
        }
    }
    return false;
}

bool Goal(const Image<Pixel>& image, int row, int col) {
    return (row == 0 || row == image.height()-1 || col == 0 || col == image.width()-1) && (image(row, col) == WHITE || image(row, col) == RED);
}


State BFS(Image<Pixel>& image, State start) {
    State s = start;
    if (Goal(image, s.row, s.col)) {
      return s;
    }

    Queue<State, List<State>> frontier;
    frontier.enqueue(s);
    std::vector<bool> explored(image.height()*image.width(), false);

    while (true) {
      if (frontier.isEmpty()) {
        s.row = -1;
        s.col = -1;
        return s;
      }

      s = frontier.peekFront();
      frontier.dequeue();

      if (Goal(image, s.row, s.col)) {
        return s;
      }

      explored[s.row*s.col] = true;

      for (int i=0; i<4; i++) {
        State s_next;
        if (i == 0) {
          s_next.row = s.row-1;
          s_next.col = s.col;
        } else if (i == 1) {
          s_next.row = s.row+1;
          s_next.col = s.col;
        } else if (i == 2) {
          s_next.row = s.row;
          s_next.col = s.col-1;
        } else if (i == 3) {
          s_next.row = s.row;
          s_next.col = s.col+1;
        }

        if (ValidMove(image, s_next) && explored[s_next.row*s_next.col] == false) {
          frontier.enqueue(s_next);
        }
      }

    }
}

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

try {
  // Read input image from file
  Image<Pixel> image = readFromFile(input_file);

  //Check if image has invalid colors
  size_t rows = image.height();
  size_t cols = image.width();
  int redCount = 0;
  State start;

  for (size_t r=0; r<rows; r++) {
    for (size_t c=0; c<cols; c++) {
      if (!ValidColorCheck(image(r,c))){
        std::cerr << "Error: Invalid color present.\n";
        return EXIT_FAILURE;
      }
      //Counts red for red check later
      if (image(r,c) == RED) {
        redCount++;
        start.row = r;
        start.col = c;
      }
    }
  }

  //Check for invalid red square count
  if (redCount != 1) {
    std::cerr << "Error: Input contains either no red pixel or more than one.\n";
    return EXIT_FAILURE;
  }

  State goal = BFS(image, start);

  if (goal.row == -1 && goal.col == -1) {
    std::cout << "No Solution Found" << std::endl;
  } else {
    //Change goal state pixel color to green
    image(goal.row, goal.col) = GREEN;
    std::cout << "Solution Found" << std::endl;
  }
  
  // Write solution image to file
  writeToFile(image, output_file);

} catch (std::exception &ex) {
  //catch used if reading in or writing to file throws an exception.
  std::cerr << ex.what() << std::endl;
  return EXIT_FAILURE;
}

return EXIT_SUCCESS;
  
}
