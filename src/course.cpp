#include "course.hpp"

Course::Course(int id_, int credit_, int prerequisite_, string name_ , vector<int> majors_id_){
    id = id_ ; 
    credit = credit_ ; 
    prerequisite = prerequisite_ ; 
    name = name_ ; 
    majors_id = majors_id_ ; 
}

void Course::check_valid_major_id(int major_id){
    for (auto id : majors_id){
        if (id == major_id)
            return ; 
    }
    throw PERMISSION_DENIED ; 
}

void Course::print()
{
    cout << id << " " << credit << " " << prerequisite << " " << name << " " ; 
    for (auto x : majors_id){
        cout << x << " " ; 
    }  
    cout << endl ;
}
