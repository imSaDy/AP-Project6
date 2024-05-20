#pragma once 

#include "global_stuff.hpp" 
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp" 
#include "major.hpp"
#include "file_reader.hpp"
#include "IOhandler.hpp"

class System {
public : 
    System(char*[]);
    void run(); 
private :
    vector <User*> users ;
    vector <Major*> majors ; 
    vector <Course*> courses ; 
    UserType user_type ; 
}; 