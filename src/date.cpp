#include "date.hpp"

Date::Date(){
}

Date::Date(string date)
{
    Tokenizer tok ;
    vector <string> tokens = tok.tokenize(date , SLASH) ; 
    year = stoi(tokens[YEAR_INDEX]) ; 
    month = stoi(tokens[MONTH_INDEX]) ; 
    day = stoi(tokens[DAY_INDEX]) ;
}

void Date::print(){
    cout << year << SLASH << month << SLASH << day ; 
}

bool Date::equal(Date other){
    return (day == other.get_day() && month == other.get_month() && year == other.get_year()) ; 
}
