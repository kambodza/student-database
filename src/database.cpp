#include "database.hpp"

void Database::addItem()
{
    auto studentToAdd = Student();
    studentToAdd.getNameFromCin();
    studentToAdd.getLastNameFromCin();
    studentToAdd.getAddressFromCin();
    studentToAdd.getIndexNumberFromCin();
    studentToAdd.getPeselFromCin();
    studentToAdd.getGenderFromCin();
    this->students_.push_back(studentToAdd);
}

vector<Student> Database::getEntries(void)
{
    return students_;
}

void Database::showCommands(void)
{
    unsigned commandNo = 0;
    bool loopGoOn = true;
    unsigned studNo = 1;

    while (loopGoOn)
    {
        this->printMenuItems();
        cin >> commandNo;
        switch (commandNo)
        {
        case 1:
            /* add student */
            this->addItem();
            break;

        case 2:
            // todo remove student
            break;

        case 3:
            /* Show all students */
            studNo = 1;
            cout << "\n";
            if(students_.empty())
            {
                cout << "Database is empty. Unable to show students \n";
            }
            else
            {
                for(Student n : students_)
                {
                    cout << studNo << ". ";
                    n.showStudent();
                    cout << "\n";
                    studNo++;
                }
            }
            break;
            
        case 10:
            loopGoOn = false;
            cout << "Closing program. See you soon! \n";
            break;
        
        default:
            cout << "This menu item is not supported, write ok enter to continue \n";
            string noUseString;
            cin >> noUseString;
            break;
        }
    }
    
}

void Database::printMenuItems(void)
{
    cout << "////STUDENT-DATABASE menu choose option:\\\\\\" << "\n";
    cout << "1 - Add Student" << "\n";
    cout << "2 - Remove Student" << "\n";
    cout << "3 - Show all Students" << "\n";
    cout << "1 - add Student" << "\n";
    cout << "1 - add Student" << "\n";
    cout << "1 - add Student" << "\n";
    cout << "1 - add Student" << "\n";
    cout << "1 - add Student" << "\n";
    cout << "10 - Close program" << "\n";
}