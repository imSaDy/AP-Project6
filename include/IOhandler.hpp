#pragma once

#include "global_stuff.hpp"
#include "file_reader.hpp"
#include "system.hpp" 

class Input{
public:
    Input(char*[]) ;
    void build_tokens(); 
    vector <string> get_tokens(); 
    vector <string> get_text_parts(); 
    void read_input();
private:
    char** arg; 
    string line ; 
    vector <string> tokens ; 
}; 
