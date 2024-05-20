#pragma once 

#include "global_stuff.hpp"

class User {
public: 
   User(int ,int ,string ,string) ; 
   virtual void print() = 0 ; 
protected: 
   int id ,major_id ; 
   string name ,password ;  
}; 