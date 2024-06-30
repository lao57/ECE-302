#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

typedef SortedList<int, List<int> > SortedListType;
typedef PriorityQueue<int, SortedListType>  PriorityQueueType;


TEST_CASE("Testing Sorted List") {
  SortedListType sl;
  REQUIRE(sl.isEmpty());
  
  sl.insert(2);
  REQUIRE(sl.getEntry(0) == 2);
  
  sl.insert(1);
  REQUIRE(sl.getEntry(0) == 1);
  REQUIRE(sl.getEntry(1) == 2);
}

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  PriorityQueueType pq;

}
