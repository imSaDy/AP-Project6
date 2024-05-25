#pragma once  

#include "global_stuff.hpp"

class Request{
public:
    Request(vector <string>) ; 
    string get_parameter(string word); 
    string get_type(); 
    string get_function_name();
private:
    vector <string> request ;
};