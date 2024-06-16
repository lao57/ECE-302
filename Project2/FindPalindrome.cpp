#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"
#include <cmath>


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
	int arr[26] = {0};
	int size = stringVector.size();
	for (int i = 0; i<size; i++){
		std::string str = stringVector[i];
		int len = str.length();
		convertToLowerCase(str);
		for (int j = 0; j < len; j++){
			char ch = str[j];
			switch(ch){
				case 'a':
                arr[0] += 1;
                break;
            case 'b':
                arr[1] += 1;
                break;
            case 'c':
                arr[2] += 1;
                break;
            case 'd':
                arr[3] += 1;
                break;
            case 'e':
                arr[4] += 1;
                break;
            case 'f':
                arr[5] += 1;
                break;
            case 'g':
                arr[6] += 1;
                break;
            case 'h':
                arr[7] += 1;
                break;
            case 'i':
                arr[8] += 1;
                break;
            case 'j':
                arr[9] += 1;
                break;
            case 'k':
                arr[10] += 1;
                break;
            case 'l':
                arr[11] += 1;
                break;
            case 'm':
                arr[12] += 1;
                break;
            case 'n':
                arr[13] += 1;
                break;
            case 'o':
                arr[14] += 1;
                break;
            case 'p':
                arr[15] += 1;
                break;
            case 'q':
                arr[16] += 1;
                break;
            case 'r':
                arr[17] += 1;
                break;
            case 's':
                arr[18] += 1;
                break;
            case 't':
                arr[19] += 1;
                break;
            case 'u':
                arr[20] += 1;
                break;
            case 'v':
                arr[21] += 1;
                break;
            case 'w':
                arr[22] += 1;
                break;
            case 'x':
                arr[23] += 1;
                break;
            case 'y':
                arr[24] += 1;
                break;
            case 'z':
                arr[25] += 1;
                break;
            default:
                break;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 26; i++){
		if((arr[i]%2)!=0){
			count += 1;
		}
	}
	if (count > 1){
		return false;
	}else{
		return true;
	}
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	
	int len1 = stringVector1.size();
	std::string v1 = {};
	for (int i = 0; i < len1; i++){
		v1 += stringVector1[i];
	}
	int len2 = stringVector2.size();
	std::string v2 = {};
	for (int i = 0; i < len2; i++){
		v2 += stringVector2[i];
	}
	convertToLowerCase(v1);
	convertToLowerCase(v2);
	if(v1.length() < v2.length()){
		for(int i = 0; i < v1.length(); i++){
			char h1 = v1[i];
			bool checker = false;
			for (int j = 0; j < v2.length(); j++){
				if (h1 == v2[j]){
					checker = true;
				}
			}
			if (checker == false){
				return false;
			}
		}
	}else {
		for(int i = 0; i < v2.length(); i++){
			char h1 = v2[i];
			bool checker = false;
			for (int j = 0; j < v1.length(); j++){
				if (h1 == v1[j]){
					checker = true;
				}
			}
			if (checker == false){
				return false;
			}
			}
	}
	return true;
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

