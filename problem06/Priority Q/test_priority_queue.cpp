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


TEST_CASE("Testing sorted list") {
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
