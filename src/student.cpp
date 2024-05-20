#include "student.hpp"
#include "database.hpp"
#include <iostream>
#include <string>
#include "gender.hpp"

using namespace std;


  Student::Student(
  string name, 
  string lastName,
  string address,
  int indexNumber,
  string pesel,
  Gender gender)
  : name_(name),
    lastName_(lastName),
    address_(address),
    indexNumber_(indexNumber),
    pesel_(pesel),
    gender_(gender)
  {
    cout << "New student added its pesel is" << pesel << "\n";
  }

  void Student::showStudent(void)
  {
    cout << "name:" << name_ <<"lastName:" << lastName_ << "adress:" << address_;
  }

  // Student::Student()
  // : name_("NULL"),
  //   lastName_("NULL"),
  //   address_("NULL"),
  //   indexNumber_(-1),
  //   pesel_("NULL"),
  //   gender_(Not_Specified)
  // {
  //     cout << "Bad parameters given for student, null entry \n";
  // }