#include "admin.hpp"

Admin::Admin() : User("0" ,"UT_account" ,"UT_account"){user_type = ADMIN;}

void Admin::print(){
    cout << id << " " << name << " " << password << endl ; 
}

void Admin::print_info(){
    cout << UT_ACCOUNT << endl ; 
}

void Admin::print_personal_page(){
    cout << UT_ACCOUNT << endl ; 
    for (int i = posts.size() - 1; i >= 0; i--){
        Post* post = posts[i] ; 
        cout << post->id << " " << post->title << endl ; 
    }
}
