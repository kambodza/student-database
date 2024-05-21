#include "student.hpp"
#include "database.hpp"
#include <iostream>
#include <string>
#include "gender.hpp"

using namespace std;

Student::Student()
: name_("NULL"),
  lastName_("NULL"),
  address_("NULL"),
  indexNumber_(-1),
  pesel_("NULL"),
  gender_(Not_Specified)
{
    // cout << "Bad parameters given for student, null entry \n";
}

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
  // cout << "New student added its PESEL is" << pesel << "\n";
}

void Student::showStudent(void)
{
  cout << "Name: " << name_ 
        <<" LastName: " << lastName_ 
        << " Adress: " << address_
        << " IndexNo: " << indexNumber_
        << " PESEL: " << pesel_
        << " Gender: " << showGender()
        << "\n";
}

void Student::showStudent(const Student & stud)
{
  cout << "Name: " << stud.name_ 
        <<" LastName: " << stud.lastName_ 
        << " Adress: " << stud.address_
        << " IndexNo: " << stud.indexNumber_
        << " PESEL: " << stud.pesel_
        // << " Gender: " << showGender() todo use reference
        << "\n";
}

string Student::showGender()
{
  if(gender_ == Male)
  {
    return "Male";
  }
  else if(gender_ == Female)
  {
    return "Female";
  }
  else
  {
    return "Not_Specified";
  }
}


  void Student::getNameFromCin(void)
  {
    cout << "Prosze podac imie studenta:" << "\n";
    cin >> ws >>  this->name_;
  }
  void Student::getLastNameFromCin(void)
  {
    cout << "Prosze podac nazwisko studenta:" << "\n";
    cin >> ws >>  this->lastName_;
  }
  void Student::getAddressFromCin(void)
  {
    string addr;
    cout << "Prosze podac caly adres studenta:" << "\n";
    cin.sync();
    getline(cin >> ws, addr, '\n');
    this->address_ = addr;
  }
  void Student::getIndexNumberFromCin(void)
  {
    cout << "Prosze podac numer indeksu studenta:" << "\n";
    cin >> ws >>  this->indexNumber_;
    //todo zmienic sposob pobierania nr indeksu, sprawdzac czy to jest liczba
  }
  void Student::getPeselFromCin(void)
  {
    cout << "Prosze podac PESEL studenta:" << "\n";
    cin >> ws >>  this->pesel_;
  }
  void Student::getGenderFromCin(void)
  {
    string genderFromUser;
    Gender genderToSet;
    cout << "Prosze podac plec studenta(Male, Female, Not_Specified):" << "\n";
    cin >> ws >> genderFromUser;

    if(genderFromUser == "Male")
    {
      genderToSet = Male;
    }
    else if(genderFromUser == "Female")
    {
      genderToSet = Female;
    }
    else
    {
      genderToSet = Not_Specified;
    }

    this->gender_ = genderToSet;
  }