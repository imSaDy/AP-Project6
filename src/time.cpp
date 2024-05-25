#include "time.hpp"

Time::Time(){
}

Time::Time(string time_str)
{
    Tokenizer tok ;
    vector <string> tokens = tok.tokenize(time_str ,COLLON) ; 
    day = tokens[0] ; 
    vector <string> times = tok.tokenize(tokens[1] ,DASH) ;
    start = stoi(times[0]) ; 
    end = stoi(times[1]) ;
}

bool Time::overlap(Time other){
    if (day != other.day) return false ; 
    if (start >= other.end || other.start >= end) return false ; 
    return true ; 
}

void Time::print(){
    cout << day << COLLON << start << DASH << end ;
}

bool Time::equal(Time other){
    if (day != other.get_day())
        return false ; 
    if (this->overlap(other))
        return false ; 
    return true ; 
}
