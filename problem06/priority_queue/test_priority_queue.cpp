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
