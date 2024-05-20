#include "course.hpp"

Course::Course(int id_, int credit_, int prerequisite_, string name_ , vector<int> majors_id_){
    id = id_ ; 
    credit = credit_ ; 
    prerequisite = prerequisite_ ; 
    name = name_ ; 
    majors_id = majors_id_ ; 
}

void Course::print(){
    cout << id << " " << credit << " " << prerequisite << " " << name << " " ; 
    for (auto x : majors_id){
        cout << x << " " ; 
    }  
    cout << endl ; 
}
