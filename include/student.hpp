#pragma once 

#include "global_stuff.hpp"
#include "user.hpp"
#include "course_offer.hpp"

class Student : public User {
public: 
    Student(int ,string ,string ,string ,string); 
    void print() ; 
    void print_personal_page(); 
    void print_info(); 
    void set_major(Major* major_){major = major_;}
    void add_course_offer(CourseOffer* course_offer){course_offers.push_back(course_offer);}
    void check_timing(CourseOffer*);
    void delete_course_offer(CourseOffer*);
    void print_course_offers();
    string get_major_id(){return major_id;}
    int get_semester(){return semester;}
private:
    vector <CourseOffer*> course_offers ; 
    int semester ;
    string major_id ; 
    Major* major ; 
}; 