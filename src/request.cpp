#include "request.hpp"

Request::Request(vector<string> request_){
    request = request_ ; 
    if (request.size() <= QUESTION_MARK_INDEX || request[QUESTION_MARK_INDEX] != QUESTION_MARK)
        throw BAD_REQUEST ; 
}

string Request::get_parameter(string word){
    for (int i = 0; i < request.size(); i++){
        if (request[i] == word){
            return request[i + 1] ; 
        }
    }
    throw BAD_REQUEST ; 
}

string Request::get_type(){
    return request[TYPE_INDEX] ; 
}

string Request::get_function_name(){
    return request[FUNCTION_NAME_INDEX] ; 
}
