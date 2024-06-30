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
	//vars
	int i = 0, len = inputString.length();


	// big while loop
	while (i < len){

		char x = inputString[i];

		//in a tag
		if (x == '<'){
			std::string tokenstr;
			while ( x != '>'){
				tokenstr + x;
				i++;
				x = inputString[i];
			}
			tokenstr + x; //adds the ">" at the end
			i++;
			if (is_validtoken(tokenstr)){
			//is_vaildtoken(tokenstr);  if true else return false
			//StringTokenType type = what_type(tokenstr);
			//TokenStruct token(type, tokenstr);
			//tokenizedInputVector.popback(token);
			}else{
				return false;
			}
		}

		//in content
		else if(x != '<'){

			std::string contentstr;
			while (x != '<'){
				contentstr + x;
				i++;
				x = inputString[i];
			}

			//is_validcont(); if true else return false
			//StringTokenType type = CONTENT;
			//TokenStruct token(type, tokenstr);
			//tokenizedInputVector.popback(token);








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
