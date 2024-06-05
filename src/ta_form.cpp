#include "ta_form.hpp"

Ta_form::Ta_form(string id_, CourseOffer* course_offer_ ,string message_) : Post(id_){
    message = message_;
    course_offer = course_offer_;
}

void Ta_form::print(bool all_info){
    buffer = id + SEP + TA_FORM_FOR + SEP + get_course_name() + SEP + COURSE + NEW_LINE ;
    if (all_info){
        try{
            course_offer->print(all_info) ; 
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
        buffer = buffer + message + NEW_LINE ;
    }
    throw buffer ; 
}

void Ta_form::delete_student_request(){
    students_id.pop_back();
}
