#include "user.hpp"

User::User(string id_, string name_, string password_){
    id = id_ ;  
    name = name_ ; 
    password = password_ ; 
    new_post_id = 1 ; 
    buffer = EMPTYSTRING ; 
}

void User::print_post(string id){
    try{
        Post* post = find_post_by_id(id) ;
        post->print(ALL_INFO);
    }catch (string &new_buffer){
        throw new_buffer ; 
    }
}

bool User::is_connect_with(User* user){
    auto it = find(all(connected_users) ,user) ; 
    if (it == connected_users.end())
        return false ; 
    return true ; 
}

void User::connect_with(User* user){
    connected_users.push_back(user) ; 
}

void User::add_post(string title, string message ,string img_src){
    posts.push_back(new Normal_Post(title ,message ,to_string(new_post_id++) ,img_src)) ; 
}

void User::delete_post(string id){
    Post* post = find_post_by_id(id) ; 
    posts.erase(find(all(posts) ,post)) ; 
}

void User::check_has_post(string id){
    for (auto post : posts){
        if (post->get_id() == id)
            return ; 
    }
    throw NOT_FOUND ; 
}

void User::notif_connected_users(string message){
    for (auto user : connected_users){
        user->add_notif(this ,message) ; 
    }
}

void User::add_notif(User *user, string message){
    notifications.push_back(new Notif(user->get_id() ,user->get_name() ,message)) ; 
}

void User::add_notif(Notif *notif){
    notifications.push_back(notif);
}

void User::print_notifications(){
    if (notifications.empty())
        throw EMPTY ; 
    buffer = EMPTYSTRING ;
    while (!notifications.empty()){
        try{
            notifications.back()->print();
        }catch (string &new_buffer){
            buffer += new_buffer ; 
        }
        notifications.pop_back() ; 
    }
    throw buffer ; 
}

void User::add_profile_image(string profile_image_){
    profile_image_src = profile_image_;
}

Post* User::find_post_by_id(string id){
    for (auto post : posts){
        if (post->get_id() == id)
            return post ; 
    }
    throw NOT_FOUND ; 
}
