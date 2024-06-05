#pragma once 

#include "global_stuff.hpp"
#include "post.hpp"

class Normal_Post : public Post {
public:
    Normal_Post(string title_ ,string message_ ,string id_ ,string img_src_ = EMPTYSTRING);
    void print(bool);
private:
    string img_src; 
    string title ,message ;
};