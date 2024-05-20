#pragma once 

#include "global_stuff.hpp"
#include "major.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp" 

vector <string> read(string path);

string substring(string& s ,int l ,int r);

vector <string> tokenize(string s ,char separator);
vector <Major*> get_majors_from_file(string major_path);
vector <Course*> get_courses_from_file(string course_path); 
vector <Student*> get_students_from_file(string student_path); 
vector <Professor*> get_professors_from_file(string professor_path);