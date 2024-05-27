#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  REQUIRE(b.getCurrentSize() == 1);
  b.remove(0);
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty() == true);
  b.getCurrentSize();
  b.add(0);
  b.add(0);
  b.add(0);
  b.add(3);
  REQUIRE(b.getCurrentSize() == 4);
  b.clear();
  REQUIRE(b.getFrequencyOf(0)==0);
  REQUIRE(b.contains(0)==false);

}
