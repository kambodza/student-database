#pragma once
#include <string.h>
#include "database.hpp"
#include "gender.hpp"

using namespace std;


class Student 
{
    private:
    string name_; 
    string lastName_;
    string address_;
    int indexNumber_;
    string pesel_;
    Gender gender_;



    public:
    Student( string name, 
             string lastName,
             string address,
             int indexNumber,
             string pesel,
             Gender gender);
    Student();
    // ~Student();


};

