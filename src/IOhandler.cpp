#include "IOhandler.hpp"

Input::Input(char *args[]){
    arg = args ; 
}

void Input::build_tokens(){
    Tokenizer tok ; 
    vector <string> parts = tok.tokenize(line ,SEP) ;
    vector <string> text_parts = get_text_parts() ;
    bool is_text = false ;
    int text_count = 0 ; 
    for (auto part : parts){
        if (part == EMPTYSTRING)
            continue ; 
        if (!is_text && part[0] == DOUBLEQUOTES){
            is_text = true ; 
            tokens.push_back(text_parts[text_count++]) ;
            if (part.size() > 1 && part.back() == DOUBLEQUOTES){
                is_text = false ; 
            }
        }
        else if (is_text){
            if (part.back() == DOUBLEQUOTES)
                is_text = false ; 
        }
        else {
            tokens.push_back(part) ; 
        }
    }
    if (tokens.back() == NEW_LINE){
        tokens.pop_back() ; 
    }
}

vector<string> Input::get_tokens(){
    return tokens ; 
}

vector<string> Input::get_text_parts(){
    vector <string> ret ; 
    string text = EMPTYSTRING ;
    bool is_text_started = false ; 
    for (auto c : line){
        if (is_text_started){
            text.push_back(c) ; 
            if (c == DOUBLEQUOTES){
                ret.push_back(text) ; 
                text = EMPTYSTRING ; 
                is_text_started = false ; 
            }
        }
        else if (c == DOUBLEQUOTES){
            text.push_back(c) ; 
            is_text_started = true ; 
        }
    }
    return ret ; 
}

void Input::read_input(){
    System system(arg) ;
    while (getline(cin ,line)){
        build_tokens() ; 
        vector <string> request_vc = get_tokens() ; 
        try{
            system.run(request_vc) ; 
        }catch(string &ex){
            cout << ex << endl ; 
        }
        tokens.clear() ;
    }
}
