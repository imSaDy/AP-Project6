#pragma once 

#include "global_stuff.hpp"

class Post {
public :
    Post(string id_);
    virtual void print(bool) = 0 ;
    string get_id(){return id;}
protected :
    string id ,buffer ;
};