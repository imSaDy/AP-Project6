#include "major.hpp"

Major::Major(int id_, string name_){
    id = id_ ;
    name = name_ ; 
}

void Major::print(){
    cout << id << " " << name << endl ; 
}
