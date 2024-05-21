#pragma once 

#include "global_stuff.hpp"
#include "course.hpp"
#include "major.hpp"

class User {
public: 
   User(int ,string ,string) ; 
   virtual void print() = 0 ; 
   virtual void print_personal_page() = 0 ;
   virtual void print_info() = 0 ; 
   void print_post(int id);
   int get_id(){return id;}
   string get_name(){return name;}
   void check_password(string password_){if(password != password_) throw PERMISSION_DENIED;}
   UserType get_user_type(){return user_type;}
   bool is_connect_with(User*);
   void connect_with(User*); 
   void add_post(string ,string);
   void delete_post(int); 
   void check_has_post(int);
   void notif_connected_users(string message); 
   void add_notif(User* user ,string message);
   void print_notifications();
protected: 
   int id ,new_post_id; 
   vector <Post*> posts ; 
   vector <User*> connected_users ; 
   vector <pair<User* ,string>> notifications ; 
   string name ,password ;  
   UserType user_type ; 
   Post* find_post_by_id(int);
}; 