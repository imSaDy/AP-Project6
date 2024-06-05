#include "course_offer.hpp"

CourseOffer::CourseOffer(string course_id_, string professor_id_, int capacity_, string class_time_, string exam_date_ ,string course_offer_id_ ,Course* course_ ,string professor_name_ ,int class_number_){
    class_number = class_number_ ; 
    course_id = course_id_ ; 
    professor_id = professor_id_ ; 
    capacity = capacity_ ; 
    class_time = Time(class_time_) ; 
    exam_date = Date(exam_date_) ; 
    course_offer_id = course_offer_id_ ; 
    course = course_ ; 
    professor_name = professor_name_ ;
    new_post_id = 1 ;  
    members.push_back(new Member(professor_id ,PROFESSOR_MEMBER));
}

void CourseOffer::print(bool all_info){
    buffer = course_offer_id + SEP + course->get_name() + SEP + to_string(capacity) + SEP + professor_name ; 
    if (all_info){
        buffer += SEP ;
        try {
            class_time.print();
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
        buffer += SEP ;
        try{
            exam_date.print() ;
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        } 
        buffer = buffer + SEP + to_string(class_number) ;
    }
    buffer += NEW_LINE ; 
    throw buffer ; 
}

bool CourseOffer::is_in_same_time(CourseOffer *course_offer){
    if (class_time.overlap(course_offer->get_class_time()))
        return true ; 
    if (exam_date.equal(course_offer->get_exam_date()))
        return true ; 
    return false ; 
}

void CourseOffer::add_post(string title, string message ,string img_src ,string author_name = EMPTYSTRING){
    posts.push_back(new Channel_Post(title ,message ,to_string(new_post_id++) ,author_name ,img_src)) ; 
}

void CourseOffer::add_member(Member* member){
    members.push_back(member);
}

void CourseOffer::delete_member_by_id(string id){
    for (auto it = members.begin(); it != members.end(); it++){
        if ((*it)->get_id() == id){
            members.erase(it) ; 
            break ; 
        }
    }
}

void CourseOffer::check_is_member(string id ,bool can_be_student){
    for (auto member : members){
        if (member->get_id() == id && (member->get_member_type() != STUDENT_MEMBER || can_be_student))
            return ; 
    }
    throw PERMISSION_DENIED ;
}

void CourseOffer::print_all_post(){
    buffer = EMPTYSTRING ; 
    for (int i = posts.size() - 1; i >= 0; i--){
        try{
            Post* post = posts[i] ; 
            post->print(LESS_INFO) ; 
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
    }
    throw buffer ;
}

void CourseOffer::print_post(string id){
    Post* post = find_post_by_id(id);
    bool all_course_info = true ; 
    buffer = EMPTYSTRING ;
    try{
        print(all_course_info) ;
    }catch (string &new_buffer){
        buffer = new_buffer ; 
    }
    try{
        post->print(ALL_INFO) ; 
    }catch (string &new_buffer){
        buffer += new_buffer ; 
    }
    throw buffer ; 
}

Post *CourseOffer::find_post_by_id(string id){
    for (auto post : posts){
        if (post->get_id() == id)
            return post ; 
    }
    throw NOT_FOUND ;
}
