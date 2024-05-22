#pragma once 

#include "global_stuff.hpp"
#include "tokenizer.hpp"

class Date {
public: 
    Date();
    Date(string date);
    void print();
    int get_year(){return year;}
    int get_month(){return month;}
    int get_day(){return day;}
    bool equal(Date);
private:
    int year ,month ,day ; 
};