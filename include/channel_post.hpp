#pragma once 

#include "global_stuff.hpp"
#include "post.hpp"

class Channel_Post : public Post {
public:
    Channel_Post(string title_ ,string message_ ,string id_ ,string author_name ,string img_src_ = EMPTYSTRING);
    void print(bool all_info);
private:
    string img_src ,author_name; 
    string title ,message ;
};