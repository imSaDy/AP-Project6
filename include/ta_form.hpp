#pragma once

#include "global_stuff.hpp"
#include "course_offer.hpp"
#include "post.hpp"

class Ta_form : public Post {
public:
    Ta_form(string id_ ,CourseOffer* course_offer_ ,string message_);
    string get_id(){return id;}
    string get_course_name(){return course_offer->get_course_name();}
    string get_student_id(){return students_id.back();}
    string get_course_offer_id(){return course_offer->get_course_offer_id();}
    void print(bool all_info);
    void check_semester(int semester){course_offer->check_semester(semester);}
    void add_student_request(string id){students_id.push_back(id);}
    int get_number_of_requests(){return students_id.size();}
    void delete_student_request();
    void add_ta_id_to_course_offer(string id){course_offer->add_member(new Member(id ,TA_MEMBER));}
    void reverse_requests(){reverse(all(students_id));}
private:
    string message ; 
    vector <string> students_id ; 
    CourseOffer* course_offer;
};