#pragma once 

#include "global_stuff.hpp" 
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp" 
#include "major.hpp"
#include "file_reader.hpp"
#include "IOhandler.hpp"
#include "admin.hpp"
#include "request.hpp"
#include "course_offer.hpp"
#include "tokenizer.hpp"

class System {
public : 
    System(char*[]);
    void run(); 
    bool is_natural_number(string); 
    bool is_arithmetic_number(string);
    void handle_request(Request*); 
    void handle_post_request(Request*); 
    void post_login(Request*); 
    void post_logout(Request*); 
    void post_connect(Request*);
    void post_post(Request*);  
    void post_course_offer(Request*);
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
private :
    int new_id_course_offer ; 
    vector <User*> users ;
    vector <Major*> majors ; 
    vector <Course*> courses ; 
    vector <CourseOffer*> course_offers ; 
    User* current_user ; 
    UserType user_type ; 
    User* find_user_by_id(int);
    Major* find_major_by_id(int); 
    Course* find_course_by_id(int); 
    CourseOffer* find_course_offer_by_id(int);
    Admin* admin; 
}; 