#include "time.hpp"

Time::Time(){
}

Time::Time(string time_str)
{
    Tokenizer tok ;
    vector <string> tokens = tok.tokenize(time_str ,COLLON) ; 
    day = tokens[TIME_DAY_INDEX] ; 
    vector <string> times = tok.tokenize(tokens[1] ,DASH) ;
    start = stoi(times[TIME_START_INDEX]) ; 
    end = stoi(times[TIME_END_INDEX]) ;
}

bool Time::overlap(Time other){
    if (day != other.day) return false ; 
    if (start >= other.end || other.start >= end) return false ; 
    return true ; 
}

void Time::print(){
    buffer = day + COLLON + to_string(start) + DASH + to_string(end) ;
    throw buffer ; 
}

bool Time::equal(Time other){
    if (day != other.get_day())
        return false ; 
    if (this->overlap(other))
        return false ; 
    return true ; 
}
