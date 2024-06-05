#include "professor.hpp"

Professor::Professor(string position_, string id_ , string major_id_, string name_, string password_) : User(id_ ,name_ ,password_){
    position = position_ ;
    major_id = major_id_ ;
    user_type = PROFESSOR ; 
    buffer = EMPTYSTRING ; 
}

void Professor::print_personal_page(){
    buffer = EMPTYSTRING ; 
    try{
        print_info();
    }catch (string &new_buffer){
        buffer = new_buffer ; 
    }
    for (int i = posts.size() - 1; i >= 0; i--){
        try{
            posts[i]->print(LESS_INFO);
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
    }
    throw buffer ; 
}

void Professor::print_info(){
    buffer = EMPTYSTRING ; 
    buffer = name + SEP + major->get_name() + SEP + position + SEP ;
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

void Professor::check_class_time(Time class_time){
    for (auto course_offer : course_offers){
        if (class_time.overlap(course_offer->get_class_time())){
            throw PERMISSION_DENIED ; 
        }
    }
}

void Professor::add_course_offer(CourseOffer* course_offer){
    course_offers.push_back(course_offer) ; 
}

void Professor::add_ta_form(CourseOffer* course_offer, string message){
    bool has_id = false ;
    for (auto course_offer_ : course_offers){
        if (course_offer_ == course_offer)
            has_id = true;
    }
    if (!has_id)
        throw PERMISSION_DENIED ;
    posts.push_back(new Ta_form(to_string(new_post_id++) ,course_offer ,message));
}

Ta_form *Professor::get_ta_form_by_id(string id){
    for (auto post : posts){
        if (post->get_id() == id){
            Ta_form* ta_form = dynamic_cast<Ta_form*>(post);
            if (ta_form != NULL){
                return ta_form ;
            }
        }
    }
    throw NOT_FOUND ; 
}
