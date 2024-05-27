#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  REQUIRE(b.getCurrentSize() == 1);
  b.remove(0);
  REQUIRE(b.isEmpty() == true);
  b.getCurrentSize();
  b.add(0);
  b.clear();
  REQUIRE(b.isEmpty() == true);
  REQUIRE(b.getFrequencyOf(0) == 0);
  REQUIRE(b.contains(0) == false);
}
