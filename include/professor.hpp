#pragma once 

#include "global_stuff.hpp"
#include "user.hpp"
#include "course_offer.hpp"

class Professor : public User{
public: 
    Professor(string ,string ,string ,string ,string); 
    void print();
    void print_personal_page();  
    void print_info();
    void set_major(Major* major_){major = major_;}
    void check_class_time(Time);
    void add_course_offer(CourseOffer*) ; 
    string get_major_id(){return major_id;}
private: 
    vector <CourseOffer*> course_offers ; 
    string major_id ; 
    Major* major ; 
    string position ; 
};