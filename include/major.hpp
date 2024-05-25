#pragma once 

#include "global_stuff.hpp" 

class Major {
public : 
    Major(string ,string); 
    void print() ; 
    string get_id(){return id;}
    string get_name(){return name;}
private : 
    string id ; 
    string name ; 
}; 