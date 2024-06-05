#pragma once 

#include "global_stuff.hpp" 
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp" 
#include "major.hpp"
#include "file_reader.hpp"
#include "admin.hpp"
#include "request.hpp"
#include "course_offer.hpp"
#include "tokenizer.hpp"
#include "ta_form.hpp"

class System {
public : 
    System(char*[]);
    void run(vector <string>); 
    bool is_natural_number(string); 
    bool is_arithmetic_number(string);
    void handle_request(Request*); 
    void handle_post_request(Request*); 
    void post_login(Request*); 
    void post_logout(Request*); 
    void post_connect(Request*);
    void post_post(Request*);
    void post_course_post(Request*);
    void post_ta_form(Request*);
    void post_course_offer(Request*);
    void post_profile_image(Request*);
    void post_ta_request(Request*);
    void post_close_ta_form(Request*);
    void notif_course_offer(Professor*);
    void handle_delete_request(Request*); 
    void delete_post(Request*);
    void delete_my_courses(Request*);
    void handle_put_request(Request*); 
    void put_my_courses(Request*);
    void handle_get_request(Request*); 
    void get_personal_page(Request*);
    void get_post(Request*);
    void get_notification(Request*);
    void get_courses(Request*);
    void get_my_courses(Request*);
    void get_course_channel(Request*);
    void get_course_post(Request*);
    void show_ta_request_info();
    bool is_system_closing_ta_form();
    void close_ta_request(string);
    void notif_members_in_course_offer(CourseOffer* course_offer);
private :
    int new_id_course_offer ; 
    vector <User*> users ;
    vector <Major*> majors ; 
    vector <Course*> courses ; 
    vector <CourseOffer*> course_offers ; 
    User* current_user ; 
    UserType user_type ; 
    User* find_user_by_id(string);
    Major* find_major_by_id(string); 
    Course* find_course_by_id(string); 
    CourseOffer* find_course_offer_by_id(string);
    Admin* admin; 
    bool is_closing_ta_form ; 
    Ta_form* closing_ta_form ; 
    string buffer ; 
}; 