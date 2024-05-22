#include "student.hpp"

Student::Student(int semester_, int id_ , int major_id_, string name, string password) : User(id_ ,name ,password){
    semester = semester_ ;
    major_id = major_id_ ;
    user_type = STUDENT ; 
}

void Student::print(){
    cout << semester << " " << id << " " << major_id << " " << name << " " << password << endl ; 
}

void Student::print_personal_page(){
    print_info() ;
    for (auto post : posts){
        cout << post->id << " " << post->title << endl ; 
    }
}

void Student::print_info(){
    cout << name << " " << major->get_name() << " " << semester << " " ;
    for (auto course_offer : course_offers){
        cout << course_offer->get_course_name() << COMMA ; 
    }
    cout << endl ; 
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
    for (auto course_offer : course_offers){
        bool all_info = true ; 
        course_offer->print(all_info) ; 
    }
}
