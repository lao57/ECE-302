#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE( "TODO", "[LinkedList]" ) {

    LinkedList<int> a;

    REQUIRE(a.getLength()==0);
    a.insert(0,5);
    REQUIRE(a.getLength()==1);
    REQUIRE_FALSE(a.insert(2,6));
    REQUIRE(a.getLength()==1);
    a.insert(0,5);
    a.insert(0,6);
    a.insert(0,5);
    a.insert(2,5);
    REQUIRE(a.getLength()==5);

    LinkedList<int> b(a);
    REQUIRE(b.getLength()==5);

    LinkedList<int> c;
    c=a;
    REQUIRE(c.getLength()==5);
    REQUIRE(c.remove(3)==true);
    REQUIRE(c.getLength()==4);

    c.clear();
    REQUIRE(c.isEmpty());
    c.insert(0,5);
    c.insert(0,5);
    c.insert(0,5);
    c.setEntry(2,7);
    REQUIRE(c.getEntry(2)==7);
    c.setEntry(0,5);
    c.setEntry(1,5);
    c.setEntry(2,3);
    c.setEntry(3,5);
    c.setEntry(4,6);
    REQUIRE(c.getEntry(2)==3);
    REQUIRE(c.getEntry(4)==6);


}
