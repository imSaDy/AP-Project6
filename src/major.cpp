#include "major.hpp"

Major::Major(string id_, string name_){
    id = id_ ;
    name = name_ ; 
}

void Major::print(){
    cout << id << SEP << name << endl ; 
}
