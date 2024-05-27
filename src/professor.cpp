#include "professor.hpp"

Professor::Professor(string position_, string id_ , string major_id_, string name_, string password_) : User(id_ ,name_ ,password_){
    position = position_ ;
    major_id = major_id_ ;
    user_type = PROFESSOR ; 
}

void Professor::print(){
    cout << position << SEP << id << SEP << major_id << SEP << name << SEP << password << endl ; 
}

void Professor::print_personal_page(){
    print_info();
    for (int i = posts.size() - 1; i >= 0; i--){
        Post* post = posts[i] ; 
        cout << post->id << SEP << post->title << endl ; 
    }
}

void Professor::print_info(){
    cout << name << SEP << major->get_name() << SEP << position << SEP ;
    bool has_print_comma = false ; 
    for (auto course_offer : course_offers){
        if (has_print_comma)
            cout << COMMA ; 
        cout << course_offer->get_course_name() ; 
        has_print_comma = true ; 
    }
    cout << endl ; 
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
