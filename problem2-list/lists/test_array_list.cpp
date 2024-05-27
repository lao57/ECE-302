#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {

  ArrayList<int> list;

  list.insert(0,5);
  list.insert(1,5);
  list.insert(2,5);
  REQUIRE(list.getLength() == 3);
  list.clear();
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty() == true);
  list.insert(0,6);
  list.insert(1,6);
  list.insert(2,6);
  REQUIRE(list.getEntry(2) == 6);
  list.setEntry(2,7);
  REQUIRE(list.getEntry(2) == 7);

  ArrayList<int> b = list;
  REQUIRE(b.remove(1) == true);
  REQUIRE(b.getLength() == 2);


}
