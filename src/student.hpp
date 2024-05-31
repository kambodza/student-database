#pragma once
#include <iostream>
#include <string>
#include "gender.hpp"

class Student 
{
    private:
    std::string name_; 
    std::string lastName_;
    std::string address_;
    int indexNumber_ = {};
    std::string pesel_;
    Gender gender_;



    public:
    /* c-tors */
    Student();
    Student( const std::string &name, 
             const std::string &lastName,
             const std::string &address,
             int indexNumber,
             const std::string &pesel,
             Gender gender);

    void showStudent() const;
    void showStudent(const Student & stud) const;
    std::string showGender() const;
    std::string showGender(const Student & stud) const;
    void getNameFromCin();
    void getLastNameFromCin();
    void getAddressFromCin();
    void getIndexNumberFromCin();
    void getPeselFromCin();
    void getGenderFromCin();
    std::string getLastName() const;
    std::string getPesel() const;
    int getIndexNo() const;

};
