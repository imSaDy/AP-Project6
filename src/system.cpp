#include "system.hpp"

System::System(char *arg[]){
    user_type = NOT_LOGIN ; 
    majors = get_majors_from_file(arg[1]) ; 
    courses = get_courses_from_file(arg[3]) ; 
    vector <Professor*> professors = get_professors_from_file(arg[4]) ;
    vector <Student*> students = get_students_from_file(arg[2]) ; 
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

void System::handle_put_request(Request* request){
}

void System::handle_get_request(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    auto it = find(all(GET_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == GET_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if ((*it) == PERSONAL_PAGE)
        get_personal_page(request) ; 
    if ((*it) == POST)
        get_post(request); 
    if ((*it) == NOTIFICATION)
        get_notification(request) ; 
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

void System::handle_delete_request(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    auto it = find(all(DELETE_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == POST_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if ((*it) == POST)
        delete_post(request) ; 
}

void System::delete_post(Request* request){
    current_user->delete_post(request->get_id_to_int()) ;
    throw OK ;
}
