#include "date.hpp"

Date::Date(){
}

Date::Date(string date)
{
    Tokenizer tok ;
    vector <string> tokens = tok.tokenize(date , SLASH) ; 
    year = stoi(tokens[0]) ; 
    month = stoi(tokens[1]) ; 
    day = stoi(tokens[2]) ;
}

void Date::print(){
    cout << year << SLASH << month << SLASH << day ; 
}

bool Date::equal(Date other){
    return (day == other.get_day() && month == other.get_month() && year == other.get_year()) ; 
}
