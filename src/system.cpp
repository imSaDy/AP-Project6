#include "system.hpp"

System::System(char *arg[]){
    is_closing_ta_form = false ; 
    new_id_course_offer = NEW_ID_COURSE_OFFER_BEGIN ; 
    user_type = NOT_LOGIN ; 
    Reader reader ; 
    majors = reader.get_majors_from_file(arg[MAJOR_FILE_INDEX]) ; 
    courses = reader.get_courses_from_file(arg[COURSE_FILE_INDEX]) ; 
    vector <Professor*> professors = reader.get_professors_from_file(arg[PROFESSOR_FILE_INDEX]) ;
    vector <Student*> students = reader.get_students_from_file(arg[STUDENT_FILE_INDEX]) ; 
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
    buffer = EMPTYSTRING ; 
}

void System::run(vector <string> request_vc){
    buffer = EMPTYSTRING ; 
    Request* request = new Request(request_vc) ; 
    handle_request(request) ; 
    throw buffer ;
}

User* System::find_user_by_id(string id){
    for (auto user : users){
        if (user->get_id() == id)
            return user ; 
    }
    throw NOT_FOUND ; 
}

Major *System::find_major_by_id(string id){
    for (auto major : majors){
        if (major->get_id() == id)
            return major ; 
    }
    throw NOT_FOUND ; 
}

Course *System::find_course_by_id(string id){
    for (auto course : courses){
        if (course->get_id() == id)
            return course ; 
    }
    throw NOT_FOUND ; 
}

CourseOffer *System::find_course_offer_by_id(string id){
    for (auto course_offer : course_offers){
        if (course_offer->get_course_offer_id() == id)
            return course_offer ; 
    }
    throw NOT_FOUND ; 
}

bool System::is_natural_number(string num){
    for (auto digit : num){
        if (digit < ZERO || digit > NINE){
            return false ; 
        }
    }
    if (num[0] == ZERO) return false ;
    return true ; 
}

bool System::is_arithmetic_number(string num){
    for (auto digit : num){
        if (digit < ZERO || digit > NINE) return false ; 
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
    if ((*it) == PROFILE_PHOTO)
        post_profile_image(request);
    if ((*it) == TA_FORM)
        post_ta_form(request);
    if ((*it) == TA_REQUEST)
        post_ta_request(request);
    if ((*it) == CLOSE_TA_FORM)
        post_close_ta_form(request);
    if ((*it) == COURSE_POST)
        post_course_post(request);
}

void System::post_login(Request* request){
    if (user_type != NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if (request->get_size() != POST_LOGIN_REQUEST_SIZE)
        throw BAD_REQUEST ;
    User* user = find_user_by_id(request->get_parameter(ID)) ;
    user->check_password(request->get_parameter(PASSWORD)) ; 
    current_user = user ; 
    user_type = user->get_user_type() ; 
    throw OK ; 
}

void System::post_logout(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if (request->get_size() != POST_LOGOUT_REQUEST_SIZE)
        throw BAD_REQUEST ;
    current_user = NULL ;
    user_type = NOT_LOGIN ;
    throw OK ;  
}

void System::post_connect(Request* request){
    if (user_type == NOT_LOGIN || user_type == ADMIN)
        throw PERMISSION_DENIED ;
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ;
    if (request->get_size() != POST_CONNECT_REQUEST_SIZE)
        throw BAD_REQUEST ;
    User* user = find_user_by_id(request->get_parameter(ID)); 
    if (current_user->is_connect_with(user) || current_user == user)
        throw BAD_REQUEST ; 
    current_user->connect_with(user) ;
    user->connect_with(current_user) ; 
    throw OK ; 
}

void System::post_post(Request* request){
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if (request->get_size() != POST_POST_REQUEST_SIZE1 && request->get_size() != POST_POST_REQUEST_SIZE2)
        throw BAD_REQUEST ;
    current_user->add_post(request->get_parameter(TITLE) ,request->get_parameter(MESSAGE) ,request->get_parameter(IMAGE)); 
    current_user->notif_connected_users(NEW_POST) ; 
    throw OK ; 
}

void System::post_course_post(Request* request){
    if (user_type != STUDENT && user_type != PROFESSOR)
        throw PERMISSION_DENIED ; 
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    if (request->get_size() != POST_COURSE_POST_REQUEST_SIZE1 && request->get_size() != POST_COURSE_POST_REQUEST_SIZE2)
        throw BAD_REQUEST ;
    CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(ID)) ; 
    course_offer->check_is_member(current_user->get_id() ,CANT_BE_STUDENT) ;
    course_offer->add_post(request->get_parameter(TITLE) ,request->get_parameter(MESSAGE) ,request->get_parameter(IMAGE) ,current_user->get_name());
    notif_members_in_course_offer(course_offer) ;
    throw OK ; 
}

void System::post_ta_form(Request* request){
    if (user_type != PROFESSOR)
        throw PERMISSION_DENIED ;
    if (request->get_size() != POST_TA_FORM_REQUEST_SIZE)
        throw BAD_REQUEST ;
    Professor* professor = dynamic_cast<Professor*>(current_user);
    CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(COURSE_ID));
    string message = request->get_parameter(MESSAGE);
    professor->add_ta_form(course_offer ,message);
    current_user->notif_connected_users(NEW_FORM);
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
    if (request->get_size() != POST_COURSE_OFFER_REQUEST_SIZE)
        throw BAD_REQUEST ;
    Course* course = find_course_by_id(request->get_parameter(COURSE_ID)) ; 
    User* user = find_user_by_id(request->get_parameter(PROFESSOR_ID)) ;
    Professor* professor = dynamic_cast<Professor*>(user) ; 
    if (user->get_user_type() != PROFESSOR)
        throw PERMISSION_DENIED ; 
    course->check_valid_major_id(professor->get_major_id()) ; 
    professor->check_class_time(Time(request->get_parameter(TIME))) ; 
    string course_id = request->get_parameter(COURSE_ID) ; 
    int capacity = stoi(request->get_parameter(CAPACITY)) ; 
    int class_number = stoi(request->get_parameter(CLASS_NUMBER))  ;
    string class_time = request->get_parameter(TIME) ; 
    string exam_date = request->get_parameter(EXAM_DATE) ; 
    CourseOffer* course_offer = new CourseOffer(course_id ,professor->get_id() ,capacity ,class_time ,exam_date ,to_string(new_id_course_offer++) ,course ,professor->get_name() ,class_number) ;
    professor->add_course_offer(course_offer) ;
    course_offers.push_back(course_offer) ;
    notif_course_offer(professor) ; 
    throw OK ; 
}

void System::post_profile_image(Request* request){
    if (user_type == NOT_LOGIN || user_type == ADMIN)
        throw PERMISSION_DENIED ;
    if (request->get_size() != POST_PROFILE_PHOTO_REQUEST_SIZE)
        throw BAD_REQUEST ;
    current_user->add_profile_image(request->get_parameter(PHOTO)); 
    throw OK ;
}

void System::post_ta_request(Request* request){
    if (user_type != STUDENT)
        throw PERMISSION_DENIED ; 
    if (request->get_size() != POST_TA_REQUEST_SIZE)
        throw BAD_REQUEST ;
    Student* student = dynamic_cast<Student*>(current_user) ;
    User* user = find_user_by_id(request->get_parameter(PROFESSOR_ID)) ; 
    Professor* professor = dynamic_cast<Professor*>(user);
    if (professor == NULL)
        throw NOT_FOUND;
    Ta_form* ta_form = professor->get_ta_form_by_id(request->get_parameter(FORM_ID));
    ta_form->check_semester(student->get_semester() - 1);
    ta_form->add_student_request(student->get_id());
    throw OK ; 
}

void System::post_close_ta_form(Request* request){
    if (user_type != PROFESSOR)
        throw PERMISSION_DENIED;
    Professor* professor = dynamic_cast<Professor*>(current_user);
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    if (request->get_size() != POST_CLOSE_TA_FORM_REQUEST_SIZE)
        throw BAD_REQUEST ;
    Ta_form* ta_form = professor->get_ta_form_by_id(request->get_parameter(ID));
    closing_ta_form = ta_form ; 
    closing_ta_form->reverse_requests();
    buffer = CLOSE_TA_FORM_MESSAGE1 + to_string(ta_form->get_number_of_requests()) + CLOSE_TA_FORM_MESSAGE2 + NEW_LINE ; 
    show_ta_request_info();
    throw buffer ; 
}

void System::notif_course_offer(Professor* professor){
    for (auto user : users){
        user->add_notif(professor ,NEW_COURSE_OFFERING) ;
    }
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
    if (request->get_size() != PUT_MY_COURSES_REQUEST_SIZE)
        throw BAD_REQUEST ;
    CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(ID)) ; 
    Student* student = dynamic_cast<Student*>(current_user) ; 
    course_offer->check_semester(student->get_semester()) ;
    course_offer->check_major(student->get_major_id()) ; 
    student->check_timing(course_offer); 
    student->add_course_offer(course_offer); 
    student->notif_connected_users(GET_COURSE) ; 
    course_offer->add_member(new Member(student->get_id() ,STUDENT_MEMBER)) ;
    throw OK ; 
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
    if ((*it) == MY_COURSES)
        get_my_courses(request) ;
    if ((*it) == COURSE_CHANNEL)
        get_course_channel(request);
    if ((*it) == COURSE_POST)
        get_course_post(request);
}

void System::get_personal_page(Request* request){
    if (user_type == ADMIN)
        throw PERMISSION_DENIED ;
    if (!is_arithmetic_number(request->get_parameter(ID))){
        throw BAD_REQUEST ;
    }
    if (request->get_size() != GET_PERSONAL_PAGE_REQUEST_SIZE)
        throw BAD_REQUEST ;
    User* user = find_user_by_id(request->get_parameter(ID)); 
    user->print_personal_page(); 
}

void System::get_post(Request* request){
    if (user_type == ADMIN)
        throw PERMISSION_DENIED ;
    if (!is_arithmetic_number(request->get_parameter(ID)))
        throw BAD_REQUEST ;
    if (!is_natural_number(request->get_parameter(POST_ID)))
        throw BAD_REQUEST ;
    if (request->get_size() != GET_POST_REQUEST_SIZE)
        throw BAD_REQUEST ;
    User* user = find_user_by_id(request->get_parameter(ID)) ; 
    user->check_has_post(request->get_parameter(POST_ID));
    try{
        user->print_info();
    }catch (string &new_buffer){
        buffer = new_buffer ; 
    }
    try{
        user->print_post(request->get_parameter(POST_ID)) ; 
    }catch (string &new_buffer){
        buffer += new_buffer ; 
    }
    throw buffer ;
}

void System::get_notification(Request* request){
    if (user_type == ADMIN)
        throw PERMISSION_DENIED ;
    if (request->get_size() != GET_NOTIFICATION_REQUEST_SIZE)
        throw BAD_REQUEST ;
    current_user->print_notifications() ;
}

void System::get_courses(Request* request){
    if (user_type == ADMIN)
        throw PERMISSION_DENIED ;
    if (request->get_size() != GET_COURSES_REQUEST_SIZE1 && request->get_size() != GET_COURSES_REQUEST_SIZE2)
        throw BAD_REQUEST ;
    bool all_courses = false ; 
    try{
        request->get_parameter(ID);
    }catch (string& ex){
        all_courses = true ; 
    }
    if (!all_courses){
        if (!is_natural_number(request->get_parameter(ID)))
            throw BAD_REQUEST ;
        CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(ID)) ; 
    }
    if (course_offers.empty())
        throw EMPTY ; 
    buffer = EMPTYSTRING ;
    for (auto course_offer : course_offers){
        if (!all_courses){
            string id = request->get_parameter(ID) ; 
            if (course_offer->get_course_offer_id() == id){
                course_offer->print(ALL_INFO) ; 
            }
        }
        else {
            try{
                course_offer->print(LESS_INFO) ; 
            }catch (string &new_buffer){
                buffer += new_buffer ; 
            }
        }
    }
    throw buffer ; 
}

void System::get_my_courses(Request* request){
    if (user_type != STUDENT)
        throw PERMISSION_DENIED ;
    if (request->get_size() != GET_MY_COURSES_REQUEST_SIZE)
        throw BAD_REQUEST ;
    Student* student = dynamic_cast<Student*>(current_user) ; 
    student->print_course_offers(); 
}

void System::get_course_channel(Request* request){
    if (user_type != STUDENT && user_type != PROFESSOR)
        throw PERMISSION_DENIED ; 
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    if (request->get_size() != GET_COURSE_CHANNEL_REQUEST_SIZE)
        throw BAD_REQUEST ;
    CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(ID));
    course_offer->check_is_member(current_user->get_id() ,CAN_BE_STUDENT);
    bool all_course_info = true ; 
    try{
        course_offer->print(all_course_info) ;
    }catch (string &new_buffer){
        buffer = new_buffer ; 
    }
    try{
        course_offer->print_all_post();
    }catch (string &new_buffer){
        buffer += new_buffer ; 
    }
    throw buffer ;
}

void System::get_course_post(Request* request){
    if (user_type != STUDENT && user_type != PROFESSOR)
        throw PERMISSION_DENIED ; 
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    if (!is_natural_number(request->get_parameter(POST_ID)))
        throw BAD_REQUEST ; 
    if (request->get_size() != GET_COURSE_POST_REQUEST_SIZE)
        throw BAD_REQUEST ; 
    CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(ID)) ; 
    course_offer->check_is_member(current_user->get_id() ,CAN_BE_STUDENT);
    course_offer->print_post(request->get_parameter(POST_ID));
}

void System::show_ta_request_info(){
    if (closing_ta_form->get_number_of_requests() == 0){
        is_closing_ta_form = false ; 
        current_user->delete_post(closing_ta_form->get_id()) ;
        return ; 
    }
    is_closing_ta_form = true ;
    User* user = find_user_by_id(closing_ta_form->get_student_id()) ; 
    Student* student = dynamic_cast<Student*>(user);
    try{
        student->print_info_for_ta_request();
    }catch(string &new_buffer){
        buffer += new_buffer ;
    }
}

bool System::is_system_closing_ta_form(){
    return is_closing_ta_form; 
}

void System::close_ta_request(string response){
    buffer = EMPTYSTRING ;
    if (response != ACCEPT && response != REJECT){
        show_ta_request_info() ; 
        throw buffer ; 
    }
    User* user = find_user_by_id(closing_ta_form->get_student_id()) ; 
    string id = closing_ta_form->get_course_offer_id() ; 
    string name = closing_ta_form->get_course_name();
    string message = TA_REQUEST_RESULT_MESSAGE + response + ED + DOT ;
    user->add_notif(new Notif(id ,name ,message)) ; 
    if (response == ACCEPT)
        closing_ta_form->add_ta_id_to_course_offer(closing_ta_form->get_student_id()) ; 
    closing_ta_form->delete_student_request();
    show_ta_request_info();
    throw buffer ; 
}

void System::notif_members_in_course_offer(CourseOffer *course_offer){
    vector <Member*> members = course_offer->get_members();
    for (auto member : members){
        User* user = find_user_by_id(member->get_id()) ;
        if (user != current_user){
            user->add_notif(new Notif(course_offer->get_course_offer_id() ,course_offer->get_course_name() ,NEW_COURSE_POST_NOTIFE));
        }
    }
}

void System::handle_delete_request(Request* request){
    auto it = find(all(DELETE_FUNCTIONS) ,request->get_function_name()) ; 
    if (it == DELETE_FUNCTIONS.end())
        throw NOT_FOUND ; 
    if (user_type == NOT_LOGIN)
        throw PERMISSION_DENIED ;
    if ((*it) == POST)
        delete_post(request) ; 
    if ((*it) == MY_COURSES)
        delete_my_courses(request) ; 
}

void System::delete_post(Request* request){
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    if (request->get_size() != DELETE_POST_REQUEST_SIZE)
        throw BAD_REQUEST ;
    current_user->delete_post(request->get_parameter(ID)) ;
    throw OK ;
}

void System::delete_my_courses(Request* request){
    if (user_type != STUDENT)
        throw PERMISSION_DENIED ; 
    if (!is_natural_number(request->get_parameter(ID)))
        throw BAD_REQUEST ; 
    if (request->get_size() != DELETE_MY_COURSES_REQUEST_SIZE)
        throw BAD_REQUEST ;
    CourseOffer* course_offer = find_course_offer_by_id(request->get_parameter(ID)) ; 
    Student* student = dynamic_cast<Student*>(current_user) ; 
    course_offer->delete_member_by_id(student->get_id()) ;
    student->delete_course_offer(course_offer) ; 
    student->notif_connected_users(DELETE_COURSE) ; 
    throw OK ; 
}
