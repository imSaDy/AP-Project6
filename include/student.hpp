#pragma once 

#include "global_stuff.hpp"
#include "user.hpp"

class Student : public User {
public: 
    Student(int ,int ,int ,string ,string); 
    void print() ; 
    void print_personal_page(); 
    void print_info(); 
    void set_major(Major* major_){major = major_;}
    int get_major_id(){return major_id;}
private:
    vector <Course*> courses ; 
    int semester ,major_id ; 
    Major* major ; 
}; 