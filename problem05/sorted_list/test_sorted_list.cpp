#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "sorted_list.hpp"
#include "list.hpp"

template class SortedList<int>;

TEST_CASE("Testing isEmpty", "[sorted list]") {
  SortedList<char> lst;
  REQUIRE(lst.isEmpty());

  lst.insert('a');
  REQUIRE(!lst.isEmpty());

  lst.removeAt(0);
  REQUIRE(lst.isEmpty());
}

TEST_CASE("Testing getLength", "[sorted list]") {
  SortedList<char> lst;
  REQUIRE(lst.getLength() == 0);

  lst.insert('b');
  REQUIRE(lst.getLength() == 1);

  lst.insert('a');
  REQUIRE(lst.getLength() == 2);

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 1);

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 0);
}

TEST_CASE("Testing insert", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
}

TEST_CASE("Testing remove", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst.removeAt(5);
  REQUIRE(lst.getLength() == 25);
  REQUIRE(lst.getEntry(5) == 'g');

  lst.removeAt(11);
  REQUIRE(lst.getLength() == 24);
  REQUIRE(lst.getEntry(11) == 'n');

  lst.removeAt(0);
  REQUIRE(lst.getLength() == 23);
  REQUIRE(lst.getEntry(0) == 'b');

  lst.removeAt(22);
  REQUIRE(lst.getLength() == 22);
  REQUIRE(lst.getEntry(21) == 'y');
}

TEST_CASE("Testing clear", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst.clear();
  REQUIRE(lst.getLength() == 0);

  c = 'a';
  while (c <= 'j') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 10);

  SortedList<char> lst_empty;
  lst_empty.clear();
  REQUIRE(lst_empty.getLength() == 0);
}

TEST_CASE("Testing getEntry", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst.getEntry(i) == 'a' + i);
  }
}

TEST_CASE("Testing getPosition empty", "[sorted list]") {
  SortedList<char> lst;
  
  // empty list
  REQUIRE(lst.getPosition('a') == -1);
}

TEST_CASE("Testing getPosition", "[sorted list]") {
  SortedList<char> lst;
  
  lst.insert('a');
  lst.insert('d');
  lst.insert('e');
  lst.insert('c');
  lst.insert('b');

  REQUIRE(lst.getPosition('a') == 0);
  REQUIRE(lst.getPosition('b') == 1);
  REQUIRE(lst.getPosition('c') == 2);
  REQUIRE(lst.getPosition('d') == 3);
  REQUIRE(lst.getPosition('e') == 4);
  // not in list
  REQUIRE(lst.getPosition('f') == -1);

}


TEST_CASE("Testing init from list", "[sorted list]") {
  List<char> unsorted;
  
  unsorted.insert(0,'a');
  unsorted.insert(1,'d');
  unsorted.insert(2,'e');
  unsorted.insert(3,'c');
  unsorted.insert(4,'b');

  SortedList<char> sorted(unsorted);

  REQUIRE(sorted.getPosition('a') == 0);
  REQUIRE(sorted.getPosition('b') == 1);
  REQUIRE(sorted.getPosition('c') == 2);
  REQUIRE(sorted.getPosition('d') == 3);
  REQUIRE(sorted.getPosition('e') == 4);
}

TEST_CASE("Testing copy", "[sorted list]") {
  SortedList<char> lst;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  SortedList<char> lst_copy = lst;

  REQUIRE(lst_copy.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst_copy.getEntry(i) == lst.getEntry(i));
  }
}

TEST_CASE("Testing copy empty", "[sorted list]") {
  SortedList<char> lst;
  SortedList<char> lst_copy = lst;

  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst_copy.getLength() == 0);
}

TEST_CASE("Testing assignment", "[sorted list]") {
  SortedList<char> lst;
  SortedList<char> lst_copy;

  char c = 'a';
  while (c <= 'z') {
    lst.insert(c);
    ++c;
  }
  REQUIRE(lst.getLength() == 26);

  lst_copy = lst;

  REQUIRE(lst_copy.getLength() == 26);

  for (int i = 0; i < 26; ++i) {
    REQUIRE(lst_copy.getEntry(i) == lst.getEntry(i));
  }
}

TEST_CASE("Testing assignment to/from empty", "[sorted list]") {
  SortedList<char> lst;
  SortedList<char> lst_copy;

  lst_copy = lst;

  REQUIRE(lst.getLength() == 0);
  REQUIRE(lst_copy.getLength() == 0);
}


TEST_CASE("Testing list exceptions", "[list]") {
  List<char> lst;

  CHECK_THROWS_AS(lst.remove(0), std::range_error);
  CHECK_THROWS_AS(lst.insert(-1,'a'), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(0), std::range_error);
  CHECK_THROWS_AS(lst.setEntry(0,'a'), std::range_error);

  lst.insert(0,'a');
  lst.insert(1,'b');

  CHECK_THROWS_AS(lst.remove(5), std::range_error);
  CHECK_THROWS_AS(lst.insert(5,'c'), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(5), std::range_error);
  CHECK_THROWS_AS(lst.setEntry(5,'c'), std::range_error);

}

TEST_CASE("Testing sorted list exceptions", "[sorted list]") {
  SortedList<char> lst;

  CHECK_THROWS_AS(lst.removeAt(0), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(0), std::range_error);
  CHECK_THROWS_AS(lst.remove(0), std::range_error);

  lst.insert('a');
  lst.insert('b');
  lst.insert('c');
  lst.insert('d');

  CHECK_THROWS_AS(lst.removeAt(4), std::range_error);
  CHECK_THROWS_AS(lst.removeAt(5), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(4), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(5), std::range_error);

  CHECK_THROWS_AS(lst.removeAt(-1), std::range_error);
  CHECK_THROWS_AS(lst.getEntry(-1), std::range_error);
}
