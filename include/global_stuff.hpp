#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std ; 

#define all(v) v.begin() ,v.end() 

const int NO_VALUE = -1 ; 
const int BACKOFSTRING = -1 ;

const int TYPE_INDEX = 0 ; 
const int FUNCTION_NAME_INDEX = 1 ; 

const char SEP = ' ' ; 
const char COLLON = ':' ; 
const char SEMICOLLON = ';' ;
const char COMMA = ',' ;  
const char DOUBLEQUOTES = '\"' ;
const char DASH = '-'  ; 
const char BACKSLASH = '\\' ;

const string NEW_LINE = "\n" ; 
const string EMPTYSTRING = "" ;
const string OK = "OK" ;
const string BAD_REQUEST = "Bad Request"  ; 
const string NOT_FOUND = "Not Found" ; 
const string PERMISSION_DENIED = "Permission Denied" ; 
const string EMPTY = "Empty" ; 
const string POST_CAP = "POST" ; 
const string GET = "GET" ; 
const string DELETE = "DELETE" ;
const string PUT = "PUT" ; 
const string LOGIN = "login" ;
const string LOGOUT = "logout" ; 
const string CONNECT = "connect" ; 
const string ID = "id" ; 
const string PASSWORD = "password" ;
const string POST = "post" ; 
const string MESSAGE = "message" ; 
const string TITLE = "title" ; 
const string UT_ACCOUNT = "UT_account" ;
const string PERSONAL_PAGE = "personal_page" ; 
const string POST_ID = "post_id" ;
const string NEW_POST = "New Post" ; 
const string NEW_COURSE_OFFERING = "New Course Offering" ; 
const string GET_COURSE = "Get Course" ; 
const string DELETE_COURSE = "Delete Course" ; 
const string NOTIFICATION = "notification" ; 
const string COURSE_OFFER = "course_offer" ;
const string COURSE_ID = "course_id" ; 
const string CAPACITY = "capacity" ; 
const string CLASS_NUMBER = "class_number" ; 
const string PROFESSOR_ID = "professor_id" ; 
const string TIME = "time" ;
const string EXAM_DATE = "exam_date" ; 
const string COURSES = "courses" ; 
const string MY_COURSES = "my_courses" ; 

enum UserType {
    STUDENT, 
    PROFESSOR, 
    ADMIN,
    NOT_LOGIN
};

struct Post{
    Post(string title_ ,string message_ ,int id_){title = title_; message = message_; id = id_;}
    int id ; 
    string title ,message ; 
};

const vector <string> request_types = {POST_CAP ,GET ,DELETE ,PUT} ; 
const vector <string> POST_FUNCTIONS = {LOGIN ,LOGOUT ,CONNECT ,POST ,COURSE_OFFER} ;
const vector <string> DELETE_FUNCTIONS = {POST ,MY_COURSES} ; 
const vector <string> GET_FUNCTIONS = {PERSONAL_PAGE ,POST ,NOTIFICATION ,COURSES ,MY_COURSES} ; 
const vector <string> PUT_FUNCTIONS = {MY_COURSES} ;





