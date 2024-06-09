/*
Converts algebraic expressions in postfix notation
to prefix notation. Valid operators are +,-,/, or *. Any
single alpha character is a valid operand.
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "algebraic_expressions.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: " << argv[0] << "requires one argument" << std::endl;
    return EXIT_FAILURE;
  }

  std::string postfix = std::string(argv[1]);
  std::string prefix;

  if (isPost(postfix)) {
    convert(postfix, prefix);
    std::cout << prefix.c_str() << std::endl;
  } else {
    std::cerr << "Error: input not in postfix format" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
};
