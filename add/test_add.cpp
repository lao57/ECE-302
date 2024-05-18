#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "add.hpp"

// force template expansion
template class Add<int>;

TEST_CASE("Test add", "[Add]"){

  Add<int> a;
  REQUIRE(a.call(1,2)==3);
}

template class Add<double>;

TEST_CASE("Test add w/double", "[Add]"){

  Add<int> a;
  REQUIRE(a.call(1,2)==3);
}

template class Add<float>;

TEST_CASE("Test add w/float", "[Add]"){

  Add<int> a;
  REQUIRE(a.call(1,2)==3);
}
