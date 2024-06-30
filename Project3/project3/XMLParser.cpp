// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser() : elementNameBag(), parseStack(), tokenizedInputVector()
{
}  // end default constructor

bool XMLParser::isgood(char x)
{
    std::string badstuff = {'!','"','#','$','%','&','(',')','*','+',',','/',';','<','>','=','?','@','[',']','^','`','{','}','|','~'};
	int len = badstuff.length();
	for (int i = 0; i < len; i++){
		if (x == badstuff[i]){
			return false;
		}
	}
	return true;
}

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{
	bool start = false, stop = false;
	for (int i = 0; i < inputString.length(); i++){
		char x = inputString[i];
		if (x == '<'){
			start = true;
		}
	}
}  // end

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	return false;
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	return false;
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	return -1;
}
