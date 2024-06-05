#pragma once 

#include "global_stuff.hpp"

class Notif{
public:
    Notif(string ,string ,string);
    void print();
private:
    string name ,id ,message ,buffer; 
};