#include "user.hpp"

User::User(string id_, string name_, string password_){
    id = id_ ;  
    name = name_ ; 
    password = password_ ; 
    new_post_id = 1 ; 
}

void User::print_post(string id){
    Post* post = find_post_by_id(id) ; 
    cout << post->id << SEP << post->title << SEP << post->message << endl ; 
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

void User::add_post(string title, string message){
    posts.push_back(new Post(title ,message ,to_string(new_post_id++))) ; 
}

void User::delete_post(string id){
    Post* post = find_post_by_id(id) ; 
    posts.erase(find(all(posts) ,post)) ; 
}

void User::check_has_post(string id){
    for (auto post : posts){
        if (post->id == id)
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
    notifications.push_back({user ,message}) ; 
}

void User::print_notifications(){
    if (notifications.empty())
        throw EMPTY ; 
    while (!notifications.empty()){
        auto user = notifications.back().first ; 
        string message = notifications.back().second ; 
        cout << user->get_id() << SEP << user->get_name() << COLLON << SEP << message << endl ; 
        notifications.pop_back() ; 
    }
}

Post* User::find_post_by_id(string id){
    for (auto post : posts){
        if (post->id == id)
            return post ; 
    }
    throw NOT_FOUND ; 
}
