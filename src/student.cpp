#include "student.hpp"

Student::Student(int semester_, string id_ , string major_id_, string name, string password) : User(id_ ,name ,password){
    semester = semester_ ;
    major_id = major_id_ ;
    user_type = STUDENT ; 
    buffer = EMPTYSTRING ; 
}

void Student::print_personal_page(){
    buffer = EMPTYSTRING ; 
    try{
        print_info() ;
    }catch (string &new_buffer){
        buffer = new_buffer ; 
    }
    for (int i = posts.size() - 1; i >= 0; i--){
        try{
            Post* post = posts[i] ; 
            post->print(LESS_INFO);
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
    }
    throw buffer ;
}

void Student::print_info(){
    buffer = name + SEP + major->get_name() + SEP + to_string(semester) + SEP ;
    bool has_print_comma = false ; 
    for (auto course_offer : course_offers){
        if (has_print_comma)
            buffer += COMMA ; 
        buffer += course_offer->get_course_name() ; 
        has_print_comma = true ; 
    }
    buffer += NEW_LINE ; 
    throw buffer ;  
}

void Student::check_timing(CourseOffer* course_offer_wanted){
    for (auto course_offer : course_offers){
        if (course_offer_wanted->is_in_same_time(course_offer))
            throw PERMISSION_DENIED ; 
    }
}

void Student::delete_course_offer(CourseOffer* course_offer){
    auto it = find(all(course_offers) ,course_offer) ; 
    if (it == course_offers.end())
        throw NOT_FOUND ; 
    course_offers.erase(it) ; 
}

void Student::print_course_offers(){
    if (course_offers.empty())
        throw EMPTY ;
    buffer = EMPTYSTRING ; 
    for (auto course_offer : course_offers){
        try{
            course_offer->print(ALL_INFO) ; 
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
    }
    throw buffer ; 
}

void Student::print_info_for_ta_request(){
    buffer = EMPTYSTRING ; 
    buffer = id + SEP + name + SEP + to_string(semester) + COLLON  ; 
    throw buffer ; 
}
