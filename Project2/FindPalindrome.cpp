#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"


using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{

	if(isPalindrome(stringer(candidateStringVector))==true && candidateStringVector.size() == size){
		vecvec.push_back(candidateStringVector);
		palcount += 1;
	}
	for (int i = 0; i < currentStringVector.size(); i++){
		std::vector<std::string> newCanVec = candidateStringVector;
		std::vector<std::string> newCurVec = currentStringVector;
		newCanVec.push_back(newCurVec[i]);
		newCurVec.erase(newCurVec.begin()+i);
		recursiveFindPalindromes(newCanVec,newCurVec);
	}
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

bool FindPalindrome::alphachecker(const std::string & value)
{
	for(int i = 0; i < value.length(); i++){
		if(isalpha(value[i]) == 0){
			return false;
		}
	}
	std::string val = value;
	convertToLowerCase(val);
	std::vector<std::string> worder = wordvctr;
	for(int i = 0; i < worder.size(); i++){
	convertToLowerCase(worder[i]);
	if (val == worder[i]){
		return false;
	}
	}
	return true;
}

bool FindPalindrome::alphacheckerstring(const std::vector<std::string> &newvec)
{
	for (int j = 0; j < newvec.size(); j++){
		int repeatcount = 0;
 		std::string val = newvec[j];
		convertToLowerCase(val);
		std::vector<std::string> worder = newvec;
		for(int i = 0; i < worder.size(); i++){
			convertToLowerCase(worder[i]);
			if (val == worder[i]){
				repeatcount += 1;
				if(repeatcount > 1){
					return false;
				}
			}
		}
	}
	return true;
}

FindPalindrome::FindPalindrome()
{
	wordvctr;
	vecvec;
	palcount = 0;
	size = 0;
	// TODO need to implement this...
}

FindPalindrome::~FindPalindrome()
{
	// TODO need to implement this...
}

int FindPalindrome::number() const
{
	// TODO need to implement this...
	return palcount;
}

void FindPalindrome::clear()
{
	wordvctr.clear();
	vecvec.clear();
	palcount = 0;
	size = 0;
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	return false;
}

bool FindPalindrome::add(const string & value)
{
	if (alphachecker(value) == false){
		return false;
	}
	palcount = 0;
	size += 1;
	vecvec.clear();
	wordvctr.push_back(value);
	std::vector<std::string> newCanVec;
	recursiveFindPalindromes(newCanVec,wordvctr);
	return true;
}

bool FindPalindrome::add(const vector<string> & stringVector)
{
	for(int i = 0; i < stringVector.size(); i++){
		if (alphachecker(stringVector[i]) == false){
			return false;
		}
	}
	if (alphacheckerstring(stringVector) == false){
		return false;
	}
	palcount = 0;
	size += stringVector.size();
	vecvec.clear();
	for (int i = 0; i < stringVector.size(); i++){
		wordvctr.push_back(stringVector[i]);
	}
	std::vector<std::string> newCanVec;
	recursiveFindPalindromes(newCanVec,wordvctr);
	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return vecvec;
}

