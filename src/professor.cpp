#include "professor.hpp"

Professor::Professor(string position_, int id_ , int major_id_, string name_, string password_) : User(id_ ,name_ ,password_){
    position = position_ ;
    major_id = major_id_ ;
    user_type = PROFESSOR ; 
}

void Professor::print(){
    cout << position << " " << id << " " << major_id << " " << name << " " << password << endl ; 
}

void Professor::print_personal_page(){
    print_info();
    for (auto post : posts){
        cout << post->id << " " << post->title << endl ; 
    }
}

void Professor::print_info(){
    cout << name << " " << major->get_name() << " " << position << " " ;
    for (auto course_offer : course_offers){
        cout << course_offer->get_course_name() << COMMA ; 
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
