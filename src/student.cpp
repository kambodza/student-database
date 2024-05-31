#include "student.hpp"
#include "database.hpp"
#include <iostream>
#include <string>
#include "gender.hpp"

Student::Student()
: name_("NULL"),
  lastName_("NULL"),
  address_("NULL"),
  indexNumber_(-1),
  pesel_("NULL"),
  gender_(Gender::Not_Specified)
{}

Student::Student(
const std::string &name, 
const std::string &lastName,
const std::string &address,
int indexNumber,
const std::string &pesel,
Gender gender)
: name_(name),
  lastName_(lastName),
  address_(address),
  indexNumber_(indexNumber),
  pesel_(pesel),
  gender_(gender)
{}

void Student::showStudent() const
{
  std::cout << "Name: " << name_ 
        <<" LastName: " << lastName_ 
        << " Adress: " << address_
        << " IndexNo: " << indexNumber_
        << " PESEL: " << pesel_
        << " Gender: " << showGender()
        << "\n";
}

std::string Student::showGender() const
{
  if(gender_ == Gender::Male)
    return "Male";
  if(gender_ == Gender::Female)
    return "Female";
 
  return "Not_Specified";
}

void Student::takeNameFromCin()
{
  std::cout << "Please provide Student's name:" << "\n";
  std::cin >> std::ws >> name_;
}

void Student::takeLastNameFromCin()
{
  std::cout << "Please provide Student's last name:" << "\n";
  std::cin >> std::ws >> lastName_;
}

void Student::takeAddressFromCin()
{
  std::string addr;
  std::cout << "Please provide Student's full address:" << "\n";
  std::cin.sync();
  std::getline(std::cin >> std::ws, addr, '\n');
  address_ = addr;
}

void Student::takeIndexNumberFromCin()
{
  std::cout << "Please provide Student's index no:" << "\n";
  std::cin >> std::ws >> indexNumber_;
}

void Student::takePeselFromCin()
{
  bool peselOkFlag = false;
  std::string peselToCheck;
  static const unsigned coefArray[10] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };

  while(!peselOkFlag)
  {
    std::cout << "Please provide Student's PESEL:" << "\n";
    std::cin >> std::ws >> peselToCheck;

    unsigned sum{};
    int controlNumber{};

    if(peselToCheck.size() != 11)
    {
      std::cout << "Student's PESEL wrong size it should be 11 digit" << "\n";
      continue;
    }

    for(unsigned i = 0; i < 10; i++)
    {
      sum += ( ( peselToCheck[i] - '0' ) * coefArray[i] ) ;
    }

    controlNumber = (10 - (sum % 10)) % 10;

    if( (peselToCheck[10] -'0') != controlNumber)
    {
      std::cout << "Student's PESEL NOT valid, control number is wrong:" << "\n";
      continue;
    }

    std::cout << "Student's PESEL is valid." << "\n";
    peselOkFlag = true;
    pesel_ = peselToCheck;
  }
}

void Student::takeGenderFromCin()
{
  std::string genderFromUser;
  Gender genderToSet;
  std::cout << "Please provide Student's gender(Male, Female, Not_Specified):" << "\n";
  std::cin >> std::ws >> genderFromUser;

  if(genderFromUser == "Male")
  {
    genderToSet = Gender::Male;
  }
  else if(genderFromUser == "Female")
  {
    genderToSet = Gender::Female;
  }
  else
  {
    genderToSet = Gender::Not_Specified;
  }

  gender_ = genderToSet;
}

std::string Student::getLastName() const
{
  return lastName_;
}

std::string Student::getPesel() const
{
  return pesel_;
}

int Student::getIndexNo() const
{
  return indexNumber_;
}
