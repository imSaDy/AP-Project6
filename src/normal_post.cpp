#include "normal_post.hpp"

Normal_Post::Normal_Post(string title_, string message_, string id_, string img_src_) : Post(id_){
    title = title_; message = message_; img_src = img_src_;
}

void Normal_Post::print(bool all_info){
    buffer = id + SEP + title ;
    if (all_info)
        buffer = buffer + SEP + message ;
    buffer += NEW_LINE ;
    throw buffer ;  
}
