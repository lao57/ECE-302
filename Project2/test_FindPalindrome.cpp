#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method


	// std::string strings(std::vector<std::string> &vec){
	// 	std::string str;
	// 	for (int i = 0; i < vec.size(); i++){
	// 		str += vec[i];
	// 	}
	// 	return str;
	// }

TEST_CASE( "property testing", "[properties]" )
{
	std::string a = "sss";
	std::string b = "sss";
	REQUIRE(a == b);


	// std::vector<std::string> vect = {"hi","my","name","is","bob"};

	// REQUIRE(strings(vect)=="himynameisbob");
}

TEST_CASE( "Test adding words", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.add("kayak"));
	REQUIRE(!b.add("kayak1"));
}

TEST_CASE("test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test vector add", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);

	FindPalindrome c;	
	std::vector<std::string> d = {"a","AA","AaA"};
	REQUIRE(c.add(d));
	REQUIRE(c.number() == 6);
}
TEST_CASE("test vector add with bad strings", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE_FALSE(b.add("Aa"));
	REQUIRE_FALSE(b.number() == 6);

	FindPalindrome c;	
	std::vector<std::string> d = {"a","AA","Aa"};
	REQUIRE_FALSE(c.add(d));
}

TEST_CASE("vecvec tester", "[FindPalindrome]"){

	FindPalindrome c;	
	std::vector<std::string> d = {"a","AA","AaA"};
	REQUIRE(c.add(d));
	REQUIRE(c.number() == 6);
	// std::vector<std::vector<std::string>> vectvec = c.toVector();
	// for(int i = 0 ; i < c.number(); i++){
	// 	std::vector<std::string> vectt = vectvec[i];
	// 	for (int j = 0; j < 3; j++){
	// 		std::cout << vectt[j];
	// 		std::cout << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
}

TEST_CASE("otis tester", "[FindPalindrome]"){

	FindPalindrome c;	
	std::vector<std::string> d = {"sit","on","a","potato","pan","otis"};
	REQUIRE(c.add(d));
	// std::vector<std::vector<std::string>> vectvec = c.toVector();
	// for(int i = 0 ; i < c.number(); i++){
	// 	std::vector<std::string> vectt = vectvec[i];
	// 	for (int j = 0; j < 3; j++){
	// 		std::cout << vectt[j];
	// 		std::cout << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
}

TEST_CASE("test otis 2", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("sit"));
	REQUIRE(b.add("on"));
	REQUIRE(b.add("a"));
	REQUIRE(b.add("potato"));
	REQUIRE(b.add("pan"));
	REQUIRE(b.add("otis"));
}
