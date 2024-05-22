#pragma once 

#include "global_stuff.hpp" 
#include "course.hpp"
#include "time.hpp"
#include "date.hpp"

class CourseOffer {
public: 
    CourseOffer(int course_id_, int professor_id_ ,int capacity_ ,string class_time_ ,string exam_date_ ,int ,Course* course_ ,string);
    Time get_class_time(){return class_time;}
    Date get_exam_date(){return exam_date;}
    int get_course_offer_id(){return course_offer_id;}
    string get_course_name(){return course->get_name();}
    void print(bool);
    void check_semester(int semester){course->check_semester(semester);}
    void check_major(int major_id){course->check_valid_major_id(major_id);} 
    bool is_in_same_time(CourseOffer* course_offer);
private:
    string professor_name;  
    int course_id ,professor_id ,capacity ,class_number ,course_offer_id;
    Time class_time ;
    Date exam_date ; 
    Course* course ; 
};