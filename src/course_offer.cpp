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
}

void CourseOffer::print(bool all_info){
    cout << course_offer_id << " " << course->get_name() << " " << capacity << " " << professor_name ; 
    if (all_info){
        cout << " " ;
        class_time.print();
        cout << " " ;
        exam_date.print() ; 
        cout << " " << class_number ;
    }
    cout << endl ; 
}

bool CourseOffer::is_in_same_time(CourseOffer *course_offer){
    if (class_time.overlap(course_offer->get_class_time()))
        return true ; 
    if (exam_date.equal(course_offer->get_exam_date()))
        return true ; 
    return false ; 
}
