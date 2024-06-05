#include "date.hpp"

Date::Date(){
}

Date::Date(string date)
{
    Tokenizer tok ;
    vector <string> tokens = tok.tokenize(date , SLASH) ; 
    year = tokens[YEAR_INDEX] ; 
    month = tokens[MONTH_INDEX] ; 
    day = tokens[DAY_INDEX] ;
}

void Date::print(){
    buffer = year + SLASH + month + SLASH + day ; 
    throw buffer ;
}

bool Date::equal(Date other){
    return (day == other.get_day() && month == other.get_month() && year == other.get_year()) ; 
}
