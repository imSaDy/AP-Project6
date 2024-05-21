#include "user.hpp"

User::User(int id_, string name_, string password_){
    id = id_ ;  
    name = name_ ; 
    password = password_ ; 
    new_post_id = 1 ; 
}

void User::print_post(int id){
    Post* post = find_post_by_id(id) ; 
    cout << post->id << " " << post->title << " " << post->message << endl ; 
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
    posts.push_back(new Post(title ,message ,new_post_id++)) ; 
}

void User::delete_post(int id){
    Post* post = find_post_by_id(id) ; 
    posts.erase(find(all(posts) ,post)) ; 
}

void User::check_has_post(int id){
    for (auto post : posts){
        if (post->id == id)
            return ; 
    }
    throw NOT_FOUND ; 
}

Post* User::find_post_by_id(int id){
    for (auto post : posts){
        if (post->id == id)
            return post ; 
    }
    throw NOT_FOUND ; 
}
