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

  // TODO
  
}

TEST_CASE("Testing Sorted List") {
  SortedListType sl;
  REQUIRE(sl.isEmpty());
  
  sl.insert(2);
  REQUIRE(sl.getEntry(0) == 2);
  
  sl.insert(1);
  REQUIRE(sl.getEntry(0) == 1);
  REQUIRE(sl.getEntry(1) == 2);
}

TEST_CASE("Testing Priority Queue Construction and isEmpty") {
  PriorityQueueType pq;
  REQUIRE(pq.isEmpty());
}

TEST_CASE("Testing Priority Queue Add and isEmpty") {
  PriorityQueueType pq;
  pq.add(10);
  REQUIRE_FALSE(pq.isEmpty());
}

TEST_CASE("Testing Priority Queue Add and Peek") {
  PriorityQueueType pq;
  pq.add(10);
  REQUIRE(pq.peek() == 10);
}

TEST_CASE("Testing Priority Queue Add Multiple") {
  PriorityQueueType pq;
  pq.add(10);
  pq.add(15);
  REQUIRE(pq.peek() == 15);
}

TEST_CASE("Testing Priority Queue Add and Remove") {
  PriorityQueueType pq;
  pq.add(10);
  pq.add(15);
  pq.remove();
  REQUIRE(pq.peek() == 10);
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
