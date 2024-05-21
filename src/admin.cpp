#include "admin.hpp"

Admin::Admin() : User(0 ,"admin" ,"UT_account"){user_type = ADMIN;}

void Admin::print(){
    cout << id << " " << name << " " << password << endl ; 
}

void Admin::print_info(){
    cout << UT_ACCOUNT << endl ; 
}

void Admin::print_personal_page(){
}
