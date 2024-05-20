#pragma once 

#include "global_stuff.hpp"

class Course {
public:
    Course(int ,int ,int ,string ,vector <int>) ;
    void print() ;
private: 
    int id ,credit ,prerequisite ; 
    string name ; 
    vector <int> majors_id ; 
};