#include <string>

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(std::string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(std::string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(const std::string &postfix, std::string &prefix) {

  
  int length = postfix.length();
  char i = postfix[length-1];

  if (isalpha(i)) {
    prefix = i + prefix;
  } else if (isoperator(i)) {

    convert(postfix.substr((length-1)/2, (length-1)/2), prefix);
    convert(postfix.substr(0, (length-1)/2), prefix);
    prefix = i + prefix;
  }
  
}
