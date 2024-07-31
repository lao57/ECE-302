#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "graph.hpp"

TEST_CASE("Test Construction", "[construction]") {
  Graph<int>  g;
  REQUIRE(g.getNumVertices() == 0);
  REQUIRE( g.add(5,2) );
  REQUIRE(g.getNumVertices() == 1);
  REQUIRE( g.add(10,5) );
  REQUIRE(g.getNumVertices() == 2);
  REQUIRE( g.add(10,2) );
  REQUIRE(g.getNumVertices() == 3);
  REQUIRE_FALSE( g.add(10,5) );
  

};