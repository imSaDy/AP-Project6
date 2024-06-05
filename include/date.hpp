#pragma once 

#include "global_stuff.hpp"
#include "tokenizer.hpp"

class Date {
public: 
    Date();
    Date(string date);
    void print();
    string get_year(){return year;}
    string get_month(){return month;}
    string get_day(){return day;}
    bool equal(Date);
private:
    string year ,month ,day ; 
    string buffer ; 
};