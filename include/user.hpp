#pragma once 

#include "global_stuff.hpp"
#include "course.hpp"
#include "major.hpp"
#include "post.hpp" 
#include "normal_post.hpp"
#include "notif.hpp" 

class User {
public: 
   User(string ,string ,string) ; 
   virtual void print_personal_page() = 0 ;
   virtual void print_info() = 0 ; 
   void print_post(string id);
   string get_id(){return id;}
   string get_name(){return name;}
   void check_password(string password_){if(password != password_){throw PERMISSION_DENIED;}}
   UserType get_user_type(){return user_type;}
   bool is_connect_with(User*);
   void connect_with(User*); 
   void add_post(string ,string ,string);
   void delete_post(string); 
   void check_has_post(string);
   void notif_connected_users(string message); 
   void add_notif(User* user ,string message);
   void add_notif(Notif* notif);
   void print_notifications();
   void add_profile_image(string);
protected: 
   int new_post_id; 
   string profile_image_src ; 
   string id ; 
   vector <Post*> posts ; 
   vector <User*> connected_users ; 
   vector <Notif*> notifications ; 
   string name ,password ;  
   UserType user_type ; 
   Post* find_post_by_id(string);
   string buffer ; 
}; 