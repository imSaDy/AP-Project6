#pragma once 

#include "global_stuff.hpp"

class Course {
public:
    Course(string ,int ,int ,string ,vector <string>) ;
    string get_id(){return id;}
    string get_name(){return name;}
    void check_valid_major_id(string);
    void print() ;
    void check_semester(int semester){if (prerequisite > semester) throw PERMISSION_DENIED;}
private: 
    int credit ,prerequisite ; 
    string name ,id ; 
    vector <string> majors_id ; 
};