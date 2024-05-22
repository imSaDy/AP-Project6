#include "system.hpp"

System::System(char *arg[]){
    new_id_course_offer = 1 ; 
    user_type = NOT_LOGIN ; 
    Reader reader ; 
    majors = reader.get_majors_from_file(arg[1]) ; 
    courses = reader.get_courses_from_file(arg[3]) ; 
    vector <Professor*> professors = reader.get_professors_from_file(arg[4]) ;
    vector <Student*> students = reader.get_students_from_file(arg[2]) ; 
    for (auto student : students){
        student->set_major(find_major_by_id(student->get_major_id())) ; 
        users.push_back(student) ; 
    }
    for (auto professor : professors){
        professor->set_major(find_major_by_id(professor->get_major_id())) ; 
        users.push_back(professor) ;
    }
    admin = new Admin(); 
    for (auto user : users){
        user->connect_with(admin) ; 
        admin->connect_with(user) ; 
    }
    users.push_back(admin) ; 
}

void System::run(){
    string input ; 
    while (getline(cin ,input)){
        Input request_line = Input(input) ; 
        request_line.build_tokens() ; 
        vector <string> request_vc = request_line.get_tokens() ; 
        Request* request = new Request(request_vc) ; 
        try{
            handle_request(request) ; 
        }catch(string &ex){
            cout << ex << endl ; 
        }
    }
}

User* System::find_user_by_id(int id){
    for (auto user : users){
        if (user->get_id() == id)
            return user ; 
    }
    throw NOT_FOUND ; 
}

Major *System::find_major_by_id(int id){
    for (auto major : majors){
        if (major->get_id() == id)
            return major ; 
    }
    throw NOT_FOUND ; 
}

Course *System::find_course_by_id(int id){
    for (auto course : courses){
        if (course->get_id() == id)
            return course ; 
    }
    throw NOT_FOUND ; 
}

CourseOffer *System::find_course_offer_by_id(int id){
    for (auto course_offer : course_offers){
        if (course_offer->get_course_offer_id() == id)
            return course_offer ; 
    }
    throw NOT_FOUND ; 
}

bool System::is_natural_number(string num){
    for (auto digit : num){
        if (digit < '0' || digit > '9') return false ; 
    }
    if (num[0] == '0') return false ;
    return true ; 
}

bool System::is_arithmetic_number(string num){
    for (auto digit : num){
        if (digit < '0' || digit > '9') return false ; 
    }
    return true;
}

void System::handle_request(Request* request){
    auto it = find(all(request_types) ,request->get_type()) ; 
    if (it == request_types.end())
        throw BAD_REQUEST ; 
    if ((*it) == POST_CAP)
        handle_post_request(request) ;
    else if ((*it) == PUT)
        handle_put_request(request) ; 
    else if ((*it) == GET)
        handle_get_request(request) ; 
    else if ((*it) == DELETE)
        handle_delete_request(request) ; 
}

void System::handle_post_request(Request* request){
    auto it = find(all(POST_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == POST_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if ((*it) == LOGIN)
        post_login(request) ; 
    if ((*it) == LOGOUT)
        post_logout(request) ; 
    if ((*it) == CONNECT)
        post_connect(request) ;
    if ((*it) == POST)
        post_post(request) ;  
    if ((*it) == COURSE_OFFER)
        post_course_offer(request) ;
}

void System::post_login(Request* request){
    if (user_type != NOT_LOGIN)
        throw PERMISSION_DENIED ; 
    User* user = find_user_by_id(request->get_id_to_int()) ;
    user->check_password(request->get_parameter(PASSWORD)) ; 
    current_user = user ; 
    user_type = user->get_user_type() ; 
    throw OK ; 
}

void System::post_logout(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    current_user = NULL ;
    user_type = NOT_LOGIN ;
    throw OK ;  
}

void System::post_connect(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ;
    User* user = find_user_by_id(request->get_id_to_int()); 
    if (current_user->is_connect_with(user) || current_user == user)
        throw BAD_REQUEST ; 
    current_user->connect_with(user) ;
    user->connect_with(current_user) ; 
    throw OK ; 
}

void System::post_post(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    current_user->add_post(request->get_parameter(TITLE) ,request->get_parameter(MESSAGE)); 
    current_user->notif_connected_users(NEW_POST) ; 
    throw OK ; 
}

void System::post_course_offer(Request* request){
    if (user_type != ADMIN)
        throw PERMISSION_DENIED ; 
    if (!is_natural_number(request->get_parameter(COURSE_ID)))
        throw BAD_REQUEST ; 
    if (!is_natural_number(request->get_parameter(CAPACITY)))
        throw BAD_REQUEST ; 
    if (!is_natural_number(request->get_parameter(CLASS_NUMBER)))
        throw BAD_REQUEST ; 
    Course* course = find_course_by_id(stoi(request->get_parameter(COURSE_ID))) ; 
    User* user = find_user_by_id(stoi(request->get_parameter(PROFESSOR_ID))) ;
    Professor* professor = dynamic_cast<Professor*>(user) ; 
    if (user->get_user_type() != PROFESSOR)
        throw PERMISSION_DENIED ; 
    course->check_valid_major_id(professor->get_major_id()) ; 
    professor->check_class_time(Time(request->get_parameter(TIME))) ; 
    int course_id = stoi(request->get_parameter(COURSE_ID)) ; 
    int capacity = stoi(request->get_parameter(CAPACITY)) ; 
    string class_time = request->get_parameter(TIME) ; 
    string exam_date = request->get_parameter(EXAM_DATE) ; 
    CourseOffer* course_offer = new CourseOffer(course_id ,professor->get_id() ,capacity ,class_time ,exam_date ,new_id_course_offer++ ,course ,professor->get_name()) ;
    professor->add_course_offer(course_offer) ; 
    course_offers.push_back(course_offer) ;
    current_user->notif_connected_users(NEW_COURSE_OFFERING) ;
    throw OK ; 
}

void System::handle_put_request(Request* request){
    auto it = find(all(PUT_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == PUT_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if (user_type != STUDENT)
        throw PERMISSION_DENIED ; 
    if ((*it) == MY_COURSES)
        put_my_courses(request); 
    
}

void System::put_my_courses(Request* request){
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    CourseOffer* course_offer = find_course_offer_by_id(request->get_id_to_int()) ; 
    Student* student = dynamic_cast<Student*>(current_user) ; 
    course_offer->check_semester(student->get_semester()) ; 
    course_offer->check_major(student->get_major_id()) ; 
    student->check_timing(course_offer); 
    student->add_course_offer(course_offer); 
    student->notif_connected_users(GET_COURSE) ; 
}

void System::handle_get_request(Request* request){
    auto it = find(all(GET_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == GET_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if ((*it) == PERSONAL_PAGE)
        get_personal_page(request) ; 
    if ((*it) == POST)
        get_post(request); 
    if ((*it) == NOTIFICATION)
        get_notification(request) ; 
    if ((*it) == COURSES)
        get_courses(request) ; 
}

void System::get_personal_page(Request* request){
    if (!is_arithmetic_number(request->get_parameter(ID)))
        throw BAD_REQUEST ;
    User* user = find_user_by_id(request->get_id_to_int()); 
    user->print_personal_page(); 
    throw OK ; 
}

void System::get_post(Request* request){
    User* user = find_user_by_id(request->get_id_to_int()) ; 
    user->check_has_post(stoi(request->get_parameter(POST_ID)));
    user->print_info(); 
    user->print_post(stoi(request->get_parameter(POST_ID))) ; 
    throw OK ; 
}

void System::get_notification(Request* request){
    current_user->print_notifications() ;
}

void System::get_courses(Request* request){
    bool all_courses = (request->get_parameter(ID) == NOT_FOUND) ; 
    if (course_offers.empty())
        throw EMPTY ; 
    for (auto course_offer : course_offers){
        if (!all_courses){
            bool all_info = true ; 
            int id = request->get_id_to_int() ; 
            if (course_offer->get_course_offer_id() == id){
                course_offer->print(all_info) ; 
            }
        }
        else {
            bool all_info = false ; 
            course_offer->print(all_info) ; 
        }
    }
}

void System::get_my_courses(Request* request){
    if (user_type != STUDENT)
        throw PERMISSION_DENIED ;
    Student* student = dynamic_cast<Student*>(current_user) ; 
    student->print_course_offers(); 
}

void System::handle_delete_request(Request* request){
    auto it = find(all(DELETE_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == POST_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if ((*it) == POST)
        delete_post(request) ; 
    if ((*it) == MY_COURSES)
        delete_my_courses(request) ; 
}

void System::delete_post(Request* request){
    current_user->delete_post(request->get_id_to_int()) ;
    throw OK ;
}

void System::delete_my_courses(Request* request){
    if (user_type != STUDENT)
        throw PERMISSION_DENIED ; 
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    CourseOffer* course_offer = find_course_offer_by_id(request->get_id_to_int()) ; 
    Student* student = dynamic_cast<Student*>(current_user) ; 
    student->delete_course_offer(course_offer) ; 
}
