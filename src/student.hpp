#pragma once
#include <iostream>
#include <string>
#include "gender.hpp"

using namespace std;


class Student 
{
    private:
    string name_; 
    string lastName_;
    string address_;
    int indexNumber_;
    int pesel_;
    Gender gender_;



    public:
    /* c-tors */
    Student();
    Student( string name, 
             string lastName,
             string address,
             int indexNumber,
             int pesel,
             Gender gender);

    void showStudent(void);
    void showStudent(const Student & stud);
    string showGender();
    string showGender(const Student & stud);
    void getNameFromCin(void);
    void getLastNameFromCin(void);
    void getAddressFromCin(void);
    void getIndexNumberFromCin(void);
    void getPeselFromCin(void);
    void getGenderFromCin(void);
    string getLastName(void);
    int getPesel(void);
    int getIndexNo(void);
    bool operator < (const Student& stud);
};
