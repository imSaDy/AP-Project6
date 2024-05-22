#pragma once 

#include "global_stuff.hpp"

class Tokenizer{
public:
    vector <string> read(string path);
    string substring(string& s ,int l ,int r);
    vector <string> tokenize(string s ,char separator);
};