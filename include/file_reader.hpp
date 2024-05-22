#pragma once 

#include "global_stuff.hpp"
#include "major.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp" 
#include "tokenizer.hpp"


string substring(string& s ,int l ,int r);
class Reader {
public:
    vector <Major*> get_majors_from_file(string major_path);
    vector <Course*> get_courses_from_file(string course_path); 
    vector <Student*> get_students_from_file(string student_path); 
    vector <Professor*> get_professors_from_file(string professor_path);
};
