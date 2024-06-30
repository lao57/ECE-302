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
	bool something = false;

	//clearing class
	clear();


	// big while loop
	while (i < len){

		char x = inputString[i];

		//in a tag
		if (x == '<'){
			something = true;
			std::string tokenstr;
			i++;
			char x = inputString[i];
			while ( x != '>'){
				tokenstr += x;
				i++;
				x = inputString[i];
			}
			i++;
			if (is_validtoken(tokenstr)){
				StringTokenType type = what_type(tokenstr);
				TokenStruct token; 
				token.tokenType = type;

				//trim based on type
				if (type == END_TAG){
					tokenstr.erase(0,1);
					if (validator_1(tokenstr) == false){
						return false;
					}
					trimmer(tokenstr);
					if (validator(tokenstr) == false){
						return false;
					}
				}
				if (type == EMPTY_TAG){
					tokenstr.erase(tokenstr.length()-1);
					if (validator_1(tokenstr) == false){
						return false;
					}
					trimmer(tokenstr);
					if (validator(tokenstr) == false){
						return false;
					}
				}
				if (type == START_TAG){
					if (validator_1(tokenstr) == false){
						return false;
					}
					trimmer(tokenstr);
					if (validator(tokenstr) == false){
						return false;
					}
				}
				if (type == DECLARATION){
					tokenstr.erase(tokenstr.length()-1);
					tokenstr.erase(0,1);
				}
				

				token.tokenString = tokenstr;
				tokenizedInputVector.push_back(token);
				tokenstr.clear();
			}else{
				return false;
			}
		}

		//in content
		else if(x != '<' && !std::isspace(x)){
			something = true;
			std::string contentstr;
			while (x != '<'){
				contentstr += x;
				i++;
				x = inputString[i];
			}

			//isvalid?????
			StringTokenType type = CONTENT;
			TokenStruct token; 
			token.tokenType = type;
			token.tokenString = contentstr;
			tokenizedInputVector.push_back(token);
			contentstr.clear();

		}
		else if (x == ' '){
			i++;
		}


	}
	if (something == false){
		return false;
	}
	return true;

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
