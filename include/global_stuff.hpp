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
const int QUESTION_MARK_INDEX = 2 ; 
const int YEAR_INDEX = 0 ; 
const int MONTH_INDEX = 1 ; 
const int DAY_INDEX = 2 ; 
const int MAJOR_ID_INDEX = 0 ; 
const int MAJOR_NAME_INDEX = 1 ; 
const int COURSE_ID_INDEX = 0 ; 
const int COURSE_CREDIT_INDEX = 2 ; 
const int COURSE_PREREQUISITE_INDEX = 3 ;
const int COURSE_NAME_INEDEX = 1 ; 
const int STUDENT_SEMESTER_INDEX = 3 ; 
const int STUDENT_ID_INDEX = 0 ; 
const int STUDENT_MAJOR_ID_INDEX = 2 ;
const int STUDENT_NAME_INDEX = 1 ; 
const int STUDENT_PASSWORD_INDEX = 4 ; 
const int PROFESSOR_POSITION_INDEX = 3 ; 
const int PROFESSOR_ID_INDEX = 0 ; 
const int PROFESSOR_MAJOR_ID_INDEX = 2 ; 
const int PROFESSOR_NAME_INDEX = 1 ; 
const int PROFESSOR_PASSWORD_INDEX = 4 ; 
const int MAJOR_FILE_INDEX = 1 ; 
const int COURSE_FILE_INDEX = 3 ; 
const int PROFESSOR_FILE_INDEX = 4 ; 
const int STUDENT_FILE_INDEX = 2 ; 
const int TIME_DAY_INDEX = 0 ; 
const int TIME_START_INDEX = 0 ; 
const int TIME_END_INDEX = 1 ; 

const int NEW_ID_COURSE_OFFER_BEGIN = 1 ; 

const int POST_LOGIN_REQUEST_SIZE = 7 ;
const int POST_LOGOUT_REQUEST_SIZE = 3 ; 
const int GET_COURSES_REQUEST_SIZE1 = 5 ; 
const int GET_COURSES_REQUEST_SIZE2 = 3 ; 
const int POST_POST_REQUEST_SIZE1 = 7 ;
const int POST_POST_REQUEST_SIZE2 = 9 ; 
const int DELETE_POST_REQUEST_SIZE = 5 ; 
const int GET_PERSONAL_PAGE_REQUEST_SIZE = 5 ; 
const int GET_POST_REQUEST_SIZE = 7 ; 
const int GET_NOTIFICATION_REQUEST_SIZE = 3 ;
const int POST_COURSE_OFFER_REQUEST_SIZE = 15 ;
const int PUT_MY_COURSES_REQUEST_SIZE = 5 ; 
const int DELETE_MY_COURSES_REQUEST_SIZE = 5 ; 
const int GET_MY_COURSES_REQUEST_SIZE = 3 ; 
const int POST_PROFILE_PHOTO_REQUEST_SIZE = 5 ;
const int POST_COURSE_POST_REQUEST_SIZE1 = 9 ;
const int POST_COURSE_POST_REQUEST_SIZE2 = 11 ;
const int GET_COURSE_CHANNEL_REQUEST_SIZE = 5 ; 
const int GET_COURSE_POST_REQUEST_SIZE = 7 ; 
const int POST_TA_FORM_REQUEST_SIZE = 7 ;
const int POST_CLOSE_TA_FORM_REQUEST_SIZE = 5 ;
const int POST_TA_REQUEST_SIZE = 7 ; 
const int POST_CONNECT_REQUEST_SIZE = 5 ; 

const char COLLON = ':' ; 
const char SEMICOLLON = ';' ;
const char COMMA = ',' ;  
const char DOUBLEQUOTES = '\"' ;
const char DASH = '-'  ; 
const char SLASH = '/' ;
const char ZERO = '0' ; 
const char NINE = '9' ;
const char DOT = '.' ; 

const string SEP = " " ;
const string QUESTION_MARK = "?" ; 
const string NEW_LINE = "\n" ; 
const string EMPTYSTRING = "" ;
const string OK = "OK\n" ;
const string BAD_REQUEST = "Bad Request\n"  ; 
const string NOT_FOUND = "Not Found\n" ; 
const string PERMISSION_DENIED = "Permission Denied\n" ; 
const string EMPTY = "Empty\n" ; 
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
const string IMAGE = "image" ; 
const string PROFILE_PHOTO = "profile_photo";
const string PHOTO = "photo";
const string TA_FORM = "ta_form"; 
const string NEW_FORM = "New Form" ;
const string TA_FORM_FOR = "TA form for";
const string COURSE = "course" ; 
const string TA_REQUEST = "ta_request";
const string FORM_ID = "form_id";
const string CLOSE_TA_FORM = "close_ta_form";
const string CLOSE_TA_FORM_MESSAGE1 = "We have received ";
const string CLOSE_TA_FORM_MESSAGE2 = " requests for the teaching assistant position" ; 
const string ACCEPT = "accept" ; 
const string REJECT = "reject" ;
const string ED = "ed" ; 
const string TA_REQUEST_RESULT_MESSAGE = "Your request to be a teaching assistant has been " ;
const string COURSE_POST = "course_post" ; 
const string NEW_COURSE_POST_NOTIFE = "New Course Post" ; 
const string NO_IMAGE = "" ; 
const string COURSE_CHANNEL = "course_channel" ; 

enum UserType {
    STUDENT, 
    PROFESSOR, 
    ADMIN,
    NOT_LOGIN
};

const vector <string> request_types = {POST_CAP ,GET ,DELETE ,PUT} ; 
const vector <string> POST_FUNCTIONS = {LOGIN ,LOGOUT ,CONNECT ,POST ,COURSE_OFFER ,PHOTO ,TA_FORM ,TA_REQUEST ,PROFILE_PHOTO ,CLOSE_TA_FORM ,COURSE_POST} ;
const vector <string> DELETE_FUNCTIONS = {POST ,MY_COURSES} ; 
const vector <string> GET_FUNCTIONS = {PERSONAL_PAGE ,POST ,NOTIFICATION ,COURSES ,MY_COURSES ,COURSE_CHANNEL ,COURSE_POST} ; 
const vector <string> PUT_FUNCTIONS = {MY_COURSES} ;

const bool ALL_INFO = true ; 
const bool LESS_INFO = false ; 
const bool CAN_BE_STUDENT = true ; 
const bool CANT_BE_STUDENT = false ; 