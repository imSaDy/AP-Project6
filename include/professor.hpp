#pragma once 

#include "global_stuff.hpp"
#include "user.hpp"

class Professor : public User{
public: 
    Professor(string ,int ,int ,string ,string); 
    void print(); 
private: 
    string position ; 
}; 