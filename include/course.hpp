#pragma once 

#include "global_stuff.hpp"

class Course {
public:
    Course(int ,int ,int ,string ,vector <int>) ;
    int get_id(){return id;}
    string get_name(){return name;}
    void check_valid_major_id(int);
    void print() ;
    void check_semester(int semester){if (prerequisite > semester) throw PERMISSION_DENIED;}
private: 
    int id ,credit ,prerequisite ; 
    string name ; 
    vector <int> majors_id ; 
};