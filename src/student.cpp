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
    cout << name << " " << major->get_name() << " " << semester << endl ;
}
