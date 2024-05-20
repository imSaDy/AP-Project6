#include "professor.hpp"

Professor::Professor(string position_, int id_ , int major_id_, string name_, string password_) : User(id_ ,major_id_ ,name_ ,password_){
    position = position_ ;
}

void Professor::print(){
    cout << position << " " << id << " " << major_id << " " << name << " " << password << endl ; 
}
