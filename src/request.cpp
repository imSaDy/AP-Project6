#include "request.hpp"

Request::Request(vector<string> request_){
    request = request_ ; 
}

string Request::get_parameter(string word){
    for (int i = 0; i < request.size(); i++){
        if (request[i] == word){
            return request[i + 1] ; 
        }
    }
    return NOT_FOUND ; 
}

string Request::get_type(){
    return request[TYPE_INDEX] ; 
}

string Request::get_function_name(){
    return request[FUNCTION_NAME_INDEX] ; 
}
