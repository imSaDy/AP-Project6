#include "file_reader.hpp"

vector <string> read(string path){
	ifstream namesFile(path) ; 
	string tmp ; 
	vector <string> input ;
	while (getline(namesFile ,tmp)){
		input.push_back(tmp) ; 
	}
	return input ; 
}

string substring(string& s ,int l ,int r){
	string sub = EMPTYSTRING ; 
	for (int i = l; i <= r; i++){
		sub.push_back(s[i]) ; 
	}
	return sub ;
}

vector <string> tokenize(string s ,char separator){
	vector <string> token ;
	int lastSeparator = BACKOFSTRING ;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == separator && lastSeparator + 1 != i){
			token.push_back(substring(s ,lastSeparator + 1 ,i - 1)) ; 
			lastSeparator = i ; 
		}
        else if (s[i] == separator){
            lastSeparator = i ; 
        }
	}
	token.push_back(substring(s ,lastSeparator + 1 ,s.size() - 1)) ; 
	if (token.back() == EMPTYSTRING)
		token.pop_back() ; 
	return token ; 
}

vector<Major*> get_majors_from_file(string major_path){
    vector <Major*> ret ; 
    vector <string> major_str = read(major_path) ;
    major_str.erase(major_str.begin()) ; 
    for (auto line : major_str){
        vector <string> detail = tokenize(line ,COMMA) ; 
        ret.push_back(new Major(stoi(detail[0]) ,detail[1])) ; 
    }
    return ret ; 
}

vector<Course *> get_courses_from_file(string course_path){
    vector <Course*> ret ; 
    vector <string> course_str = read(course_path) ;
    course_str.erase(course_str.begin()) ; 
    for (auto line : course_str){
        vector <string> detail = tokenize(line ,COMMA) ; 
        vector <string> major_id = tokenize(detail[4] ,SEMICOLLON) ;
        vector <int> major_id_int ; 
        for (auto id : major_id){
            major_id_int.push_back(stoi(id)) ; 
        }
        ret.push_back(new Course(stoi(detail[0]) ,stoi(detail[2]) ,stoi(detail[3]) ,detail[1] ,major_id_int)) ; 
    }
    return ret ; 
}

vector<Student *> get_students_from_file(string student_path){
    vector <Student*> ret ; 
    vector <string> student_str = read(student_path) ;
    student_str.erase(student_str.begin()) ; 
    for (auto line : student_str){
        vector <string> detail = tokenize(line ,COMMA) ; 
        ret.push_back(new Student(stoi(detail[3]) ,stoi(detail[0]) ,stoi(detail[2]) ,detail[1] ,detail[4])) ; 
    }
    return ret ;
}

vector<Professor *> get_professors_from_file(string professor_path){
    vector <Professor*> ret ; 
    vector <string> professor_str = read(professor_path) ;
    professor_str.erase(professor_str.begin()) ; 
    for (auto line : professor_str){
        vector <string> detail = tokenize(line ,COMMA) ; 
        ret.push_back(new Professor(detail[3] ,stoi(detail[0]) ,stoi(detail[2]) ,detail[1] ,detail[4])) ; 
    }
    return ret ; 
}
