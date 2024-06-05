#pragma once 

#include "global_stuff.hpp" 
#include "course.hpp"
#include "time.hpp"
#include "date.hpp"
#include "channel_post.hpp"
#include "member.hpp"

class CourseOffer {
public: 
    CourseOffer(string course_id_, string professor_id_ ,int capacity_ ,string class_time_ ,string exam_date_ ,string ,Course* course_ ,string ,int);
    Time get_class_time(){return class_time;}
    Date get_exam_date(){return exam_date;}
    string get_course_offer_id(){return course_offer_id;}
    string get_course_name(){return course->get_name();}
    void print(bool);
    void check_semester(int semester){course->check_semester(semester);}
    void check_major(string major_id){course->check_valid_major_id(major_id);} 
    bool is_in_same_time(CourseOffer* course_offer);
    void add_post(string ,string ,string ,string);
    void add_member(Member* member);
    void delete_member_by_id(string id);
    void check_is_member(string id ,bool can_be_student);
    vector <Member*> get_members(){return members;}
    void print_all_post() ; 
    void print_post(string id);
private:
    string professor_name ,course_id ,professor_id ,course_offer_id ,buffer ;  
    int capacity ,class_number ,new_post_id;
    Time class_time ;
    Date exam_date ; 
    Course* course ; 
    vector<Member*> members ; 
    vector <Post*> posts ; 
    Post* find_post_by_id(string id);
}; 