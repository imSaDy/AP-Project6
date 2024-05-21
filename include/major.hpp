#pragma once 

#include "global_stuff.hpp" 

class Major {
public : 
    Major(int ,string); 
    void print() ; 
    int get_id(){return id;}
    string get_name(){return name;}
private : 
    int id ; 
    string name ; 
}; 