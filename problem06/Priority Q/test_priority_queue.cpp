#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

typedef SortedList<int, List<int> > SortedListType;
typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  PriorityQueueType pq;

  for (int i = 0; i < 10){
    pq.add(i+1);
    REQUIRE(pq.peek() == i+1);
  }
  
}

TEST_CASE("Priority: Testing Priority Queue Add and Remove Multiple") {
  PriorityQueueType pq;
  pq.add(10);
  pq.add(5);
  pq.add(15);
  pq.remove();
  REQUIRE(pq.peek() == 10);
  pq.remove();
  REQUIRE(pq.peek() == 5);
  pq.remove();
  REQUIRE(pq.isEmpty());
}
