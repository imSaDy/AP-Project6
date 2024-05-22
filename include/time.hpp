#pragma once 
 
#include "global_stuff.hpp"
#include "tokenizer.hpp"

class Time {
public: 
    Time();
    Time(string time_str);   
    bool overlap(Time other);
    void print();
    bool equal(Time) ; 
    string get_day(){return day;}
private: 
    string day ; 
    int start ,end ; 
};