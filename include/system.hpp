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
    void handle_delete_request(Request*); 
    void delete_post(Request*);
    void handle_put_request(Request*); 
    void handle_get_request(Request*); 
    void get_personal_page(Request*);
    void get_post(Request*);
    void get_notification(Request*);
private :
    vector <User*> users ;
    vector <Major*> majors ; 
    vector <Course*> courses ; 
    User* current_user ; 
    UserType user_type ; 
    User* find_user_by_id(int);
    Major* find_major_by_id(int); 
    Admin* admin; 
}; 