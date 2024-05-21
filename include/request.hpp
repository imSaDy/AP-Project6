#pragma once  

#include "global_stuff.hpp"

class Request{
public:
    Request(vector <string>) ; 
    int get_id_to_int(){return stoi(get_parameter(ID));}
    string get_parameter(string word); 
    string get_type(); 
    string get_function_name();
private:
    vector <string> request ;
};