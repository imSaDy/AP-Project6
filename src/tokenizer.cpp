#include "tokenizer.hpp"

vector <string> Tokenizer::read(string path){
	ifstream namesFile(path) ; 
	string tmp ; 
	vector <string> input ;
	while (getline(namesFile ,tmp)){
		input.push_back(tmp) ; 
	}
	return input ; 
}

string Tokenizer::substring(string& s ,int l ,int r){
	string sub = EMPTYSTRING ; 
	for (int i = l; i <= r; i++){
		sub.push_back(s[i]) ; 
	}
	return sub ;
}

vector <string> Tokenizer::tokenize(string s ,char separator){
	vector <string> token ;
	int lastSeparator = BACKOFSTRING ;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == separator && lastSeparator + 1 != i){
			token.push_back(substring(s ,lastSeparator + 1 ,i - 1)) ; 
			lastSeparator = i ; 
		}
        else if (s[i] == separator){
            lastSeparator = i ; 
        }
	}
	token.push_back(substring(s ,lastSeparator + 1 ,s.size() - 1)) ; 
	if (token.back() == EMPTYSTRING)
		token.pop_back() ; 
	return token ; 
}