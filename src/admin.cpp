#include "admin.hpp"

Admin::Admin() : User("0" ,"UT_account" ,"UT_account"){user_type = ADMIN;}

void Admin::print_info(){
    buffer = UT_ACCOUNT + NEW_LINE ; 
    throw buffer ; 
}

void Admin::print_personal_page(){
    buffer = UT_ACCOUNT + NEW_LINE ; 
    for (int i = posts.size() - 1; i >= 0; i--){
        try{
            Post* post = posts[i] ; 
            post->print(LESS_INFO); 
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
    }
    throw buffer ;
}
