#include "system.hpp"

System::System(char *arg[]){
    user_type = NOT_LOGIN ; 
    static int cnt = 0 ; 
    majors = get_majors_from_file(arg[1]) ; 
    courses = get_courses_from_file(arg[3]) ; 
    vector <Professor*> professors = get_professors_from_file(arg[4]) ;
    vector <Student*> students = get_students_from_file(arg[2]) ; 
    for (auto student : students){
        users.push_back(student) ; 
    }
    for (auto professor : professors){
        users.push_back(professor) ;
    }
}

void System::run(){
    string input ; 
    while (getline(cin ,input)){
        Input request_line = Input(input) ; 
        request_line.build_tokens() ; 
        vector <string> request = request_line.get_tokens() ; 
    }
}
