#include "channel_post.hpp"

Channel_Post::Channel_Post(string title_, string message_, string id_, string author_name_, string img_src_) : Post(id_){
    title = title_ ;
    message = message_ ; 
    id = id_ ; 
    img_src = img_src ;
    author_name = author_name_ ; 
    buffer = EMPTYSTRING ;
}

void Channel_Post::print(bool all_info){
    buffer = id + SEP + author_name + SEP + title ; 
    if (all_info){
        buffer = buffer + SEP + message ;
    }
    buffer = buffer + NEW_LINE ;
    throw buffer ; 
}
