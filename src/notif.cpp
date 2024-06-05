#include "notif.hpp"

Notif::Notif(string id_, string name_, string message_){
    name = name_ ; 
    id = id_ ; 
    message = message_ ; 
}

void Notif::print(){
    buffer = id + SEP + name + COLLON + SEP + message + NEW_LINE ; 
    throw buffer ; 
}
