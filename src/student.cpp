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
{}

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
{}

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
        << " Gender: " << showGender(stud)
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
string Student::showGender(const Student & stud)
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
  cout << "Please provide Student's name:" << "\n";
  cin >> ws >> this->name_;
}
void Student::getLastNameFromCin(void)
{
  cout << "Please provide Student's last name:" << "\n";
  cin >> ws >> this->lastName_;
}
void Student::getAddressFromCin(void)
{
  string addr;
  cout << "Please provide Student's full address:" << "\n";
  cin.sync();
  getline(cin >> ws, addr, '\n');
  this->address_ = addr;
}
void Student::getIndexNumberFromCin(void)
{
  cout << "Please provide Student's index no:" << "\n";
  cin >> ws >> this->indexNumber_;
  //todo zmienic sposob pobierania nr indeksu, sprawdzac czy to jest liczba
}
void Student::getPeselFromCin(void)
{
  bool peselOkFlag = false;
  string peselToCheck;
  static const unsigned coefArray[10] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };
  unsigned sum = 0;
  int controlNumber = 0;

  while(peselOkFlag == false)
  {
    cout << "Please provide Student's PESEL:" << "\n";
    cin >> ws >> peselToCheck;

    sum = 0;
    controlNumber = 0;
    //todo sprawdzanie peselu ( ilosc znakow, wzor na jego obliczanie)
    if(peselToCheck.size() == 11)
    {
      for(unsigned i = 0; i < 10; i++)
      {
        sum += ( ( peselToCheck.at(i) - '0' ) * coefArray[i] ) ;
      }

      controlNumber = 10 - (sum % 10);
      if(controlNumber < 0) 
      {
        controlNumber = 0;
      }

      if( (peselToCheck.at(10) -'0') == controlNumber)
      {
        cout << "Student's PESEL is valid:" << "\n";
        peselOkFlag = true;
        this->pesel_ = peselToCheck;
      }
      else
      {
        cout << "Student's PESEL NOT valid, control number is wrong:" << "\n";
      }

    }
    else
    {
      cout << "Student's PESEL wrong size it should be 11 digit" << "\n";
    }
  }
}
void Student::getGenderFromCin(void)
{
  string genderFromUser;
  Gender genderToSet;
  cout << "Please provide Student's gender(Male, Female, Not_Specified):" << "\n";
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

string Student::getLastName(void)
{
    return lastName_;
}

string Student::getPesel(void)
{
    return pesel_;
}

int Student::getIndexNo(void)
{
  return indexNumber_;
}


