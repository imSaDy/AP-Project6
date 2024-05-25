#include "file_reader.hpp"

vector<Major*> Reader::get_majors_from_file(string major_path){
    Tokenizer tok ; 
    vector <Major*> ret ; 
    vector <string> major_str = tok.read(major_path) ;
    major_str.erase(major_str.begin()) ; 
    for (auto line : major_str){
        vector <string> detail = tok.tokenize(line ,COMMA) ; 
        ret.push_back(new Major(detail[0] ,detail[1])) ; 
    }
    return ret ; 
}

vector<Course *> Reader::get_courses_from_file(string course_path){
    Tokenizer tok ; 
    vector <Course*> ret ;
    vector <string> course_str = tok.read(course_path) ;
    course_str.erase(course_str.begin()) ; 
    for (auto line : course_str){
        vector <string> detail = tok.tokenize(line ,COMMA) ; 
        vector <string> major_id = tok.tokenize(detail[4] ,SEMICOLLON) ;
        vector <string> major_id_int ; 
        for (auto id : major_id){
            major_id_int.push_back(id) ; 
        }
        ret.push_back(new Course(detail[0] ,stoi(detail[2]) ,stoi(detail[3]) ,detail[1] ,major_id_int)) ; 
    }
    return ret ; 
}

vector<Student *> Reader::get_students_from_file(string student_path){
    Tokenizer tok ;
    vector <Student*> ret ; 
    vector <string> student_str = tok.read(student_path) ;
    student_str.erase(student_str.begin()) ; 
    for (auto line : student_str){
        vector <string> detail = tok.tokenize(line ,COMMA) ; 
        ret.push_back(new Student(stoi(detail[3]) ,detail[0] ,detail[2] ,detail[1] ,detail[4])) ; 
    }
    return ret ;
}

vector<Professor*> Reader::get_professors_from_file(string professor_path){
    Tokenizer tok ;
    vector <Professor*> ret ; 
    vector <string> professor_str = tok.read(professor_path) ;
    professor_str.erase(professor_str.begin()) ; 
    for (auto line : professor_str){
        vector <string> detail = tok.tokenize(line ,COMMA) ; 
        ret.push_back(new Professor(detail[3] ,detail[0] ,detail[2] ,detail[1] ,detail[4])) ; 
    }
    return ret ; 
}
