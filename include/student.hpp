#pragma once 

#include "global_stuff.hpp"
#include "user.hpp"

class Student : public User {
public: 
    Student(int ,int ,int ,string ,string); 
    void print() ; 
private:
    int semester ; 
}; 