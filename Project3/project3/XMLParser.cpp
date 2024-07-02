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
			if (inputString[i] == '>'){
				return false;
			}

			if (i >=  len){
				return false;
			}
			x = inputString[i];
			while ( x != '>' && i < len){
				tokenstr += x;
				i++;
				if( i >= len){
					return false;
				}
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
		}else if (x == '>'){
			return false;
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
		}else{
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
	int len = tokenizedInputVector.size();
	if ( len == 0){
		return false;
	}else if(tokenizedInputVector[0].tokenType != START_TAG && tokenizedInputVector[0].tokenType != DECLARATION){
		return false;
	}
	
	int num_o_starts = 0;
	for (int i = 0; i < len; i++){
		if (tokenizedInputVector[i].tokenType == START_TAG){
			if(num_o_starts > 0 && parseStack.isEmpty() == true){
				return false;
			}
			parseStack.push(tokenizedInputVector[i].tokenString);
			elementNameBag.add(tokenizedInputVector[i].tokenString);
			num_o_starts++;
		}else if (tokenizedInputVector[i].tokenType == END_TAG){
			if (tokenizedInputVector[i].tokenString != parseStack.peek()){
				return false;
			}else{
				parseStack.pop();
			}
		}else if (tokenizedInputVector[i].tokenType == DECLARATION){
			if (!parseStack.isEmpty()){
				return false;
			}
		}
	}
	return parseStack.isEmpty();
}

// TODO: Implement the clear method here
void XMLParser::clear()
{
	parseStack.clear();
	elementNameBag.clear();
	tokenizedInputVector.clear();

}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if (tokenizedInputVector.empty() || parseStack.size() != 0) {
        throw std::logic_error("Input not tokenized and parsed.");
    }
    if (elementNameBag.isEmpty()) {
        throw std::logic_error("Input not tokenized and parsed.");
    }

	return elementNameBag.contains(inputString);
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if (tokenizedInputVector.empty() || parseStack.size() != 0) {
        throw std::logic_error("Input not tokenized and parsed.");
    }

    if (elementNameBag.getFrequencyOf(inputString) == 0) {
        throw std::logic_error("Input not parsed.");
    }
	return elementNameBag.getFrequencyOf(inputString);
}