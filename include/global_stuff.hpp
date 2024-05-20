#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std ; 

const int NO_VALUE = -1 ; 
const int BACKOFSTRING = -1 ;

const char SEP = ' ' ; 
const char COLLON = ':' ; 
const char SEMICOLLON = ';' ;
const char COMMA = ',' ;  
const char DOUBLEQUOTES = '\"' ; 

const string NEW_LINE = "\n" ; 
const string EMPTYSTRING = "" ;
const string OK = "OK" ;
const string BAD_REQUEST = "Bad Request"  ; 
const string NOT_FOUND = "Not Found" ; 
const string PERMISSION_DENIED = "Permission Denied" ; 
const string EMPTY = "Empty" ; 

enum UserType {
    STUDENT, 
    PROFESSOR, 
    ADMIN,
    NOT_LOGIN
};