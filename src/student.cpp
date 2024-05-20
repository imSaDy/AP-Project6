#include "student.hpp"

Student::Student(int semester_, int id_ , int major_id_, string name, string password) : User(id_ ,major_id_ ,name ,password){
    semester = semester_ ;
}

void Student::print(){
    cout << semester << " " << id << " " << major_id << " " << name << " " << password << endl ; 
}
