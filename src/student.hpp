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
    std::string showGender() const;
    void takeNameFromCin();
    void takeLastNameFromCin();
    void takeAddressFromCin();
    void takeIndexNumberFromCin();
    void takePeselFromCin();
    void takeGenderFromCin();
    std::string getLastName() const;
    std::string getPesel() const;
    int getIndexNo() const;

};
