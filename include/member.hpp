#pragma once 

#include "global_stuff.hpp"

enum MemberType{
    STUDENT_MEMBER,
    TA_MEMBER,
    PROFESSOR_MEMBER
};

class Member {
public: 
    Member(string id_ ,MemberType member_type_);
    string get_id(){return id;}
    MemberType get_member_type(){return member_type;}
private:
    string id ; 
    MemberType member_type ; 
};