#include "database.hpp"
#include <algorithm>

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

void Database::commandsHandler(void)
{
    unsigned commandNo = 0;
    bool loopGoOn = true;
    unsigned studNo = 1;
    int pos = -1;

    while (loopGoOn)
    {
        this->printMenuItems();
        cin >> ws >> commandNo;
        switch (commandNo)
        {
        case 1:
            /* add student */
            this->addItem();
            break;

        case 2:
            /* remove student */
            pos = searchByIndexNo();
            if( pos != -1)
            {
                removeByIndexNo(pos);
                cout << "Student is erased successfully!\n";
            }
            else
            {
                cout << "Unable to delete student!\n";
            }
            break;

        case 3:
            /* Show all students */
            printDatabaseEntries();
            break;

        case 4:
            searchByLastName();
            break;
            
        case 5:
            searchByPesel();
            break;
        case 6:
            sortByPesel();
            break;

        case 7:
            sortByLastname();
            break;
        case 8:

            break;

        case 10:
            loopGoOn = false;
            cout << "Closing program. See you soon! \n";
            break;
        
        default:
            cout << "This menu item is not supported, write ok + enter to continue \n";
            string noUseString;
            cin >> ws >> noUseString;
            break;
        }
    }
    
}

void Database::printMenuItems(void)
{
    cout << "\n" << "\n" << "\n" << "\n";
    cout << "////STUDENT-DATABASE menu choose option:\\\\\\\\" << "\n";
    cout << "1 - Add Student" << "\n";
    cout << "2 - Remove Student" << "\n";
    cout << "3 - Show all Students" << "\n";
    cout << "4 - Search Student by lastname" << "\n";
    cout << "5 - Search Student by PESEL" << "\n";
    cout << "6 - Sort Students by PESEL" << "\n";
    cout << "7 - Sort Students by lastname" << "\n";
    cout << "10 - Close program" << "\n";
}

void Database::printDatabaseEntries(void)
{
    unsigned studNo = 1;
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
}

void Database::searchByLastName(void)
{
    string nameToSearch;
    bool foundFlag = false;

    if(students_.empty())
    {
        cout << "Database is empty. Unable to search students \n";
    }
    else
    {
        cout << "Enter last name to search:\n";
        cin >> ws >> nameToSearch;

        for(Student n : students_)
        {
            if(n.getLastName() == nameToSearch)
            {
                cout << "Entry is found!\n";
                n.showStudent();
                cout << "\n";
                foundFlag = true;
            }
        }

        if( foundFlag == false )
        {
            cout << "Student named" << nameToSearch << "is not found!\n";
        }
    }
}

void Database::searchByPesel(void)
{
    int peselToSearch;
    bool foundFlag = false;

    if(students_.empty())
    {
        cout << "Database is empty. Unable to search students \n";
    }
    else
    {
        cout << "Enter PESEL to search:\n";
        cin >> ws >> peselToSearch;

        for(Student n : students_)
        {
            if(n.getPesel() == peselToSearch)
            {
                cout << "Entry is found!\n";
                n.showStudent();
                cout << "\n";
                foundFlag = true;
            }
        }

        if( foundFlag == false )
        {
            cout << "Student with PESEL " << peselToSearch << " is not found!\n";
        }
    }

}
int Database::searchByIndexNo(void)
{
    int idxToSearch;
    bool foundFlag = false;

    int position = -1;

    if(students_.empty())
    {
        cout << "Database is empty. Unable to search students \n";
    }
    else
    {
        cout << "Enter Index number to search:\n";
        cin >> ws >> idxToSearch;

        position = 0;

        for(Student n : students_)
        {
            if(n.getIndexNo() == idxToSearch)
            {
                cout << "Entry is found!\n";
                n.showStudent();
                cout << "\n";
                foundFlag = true;
                break;
            }
            position++;
        }

        if( foundFlag == false )
        {
            cout << "Student with indexNumber " << idxToSearch << " is not found!\n";
            position = -1;
        }
    }

    return position;
}

void Database::sortByPesel(void)
{
    if(students_.empty())
    {
        cout << "Database is empty. Unable to sort students \n";
    }
    else
    {
        cout << "Sorting by PESEL..\n";
        sort(students_.begin(), students_.end(), [](Student a, Student b)
        {
            return a.getPesel() < b.getPesel();
        });
        cout << "Database is sorted: \n";
        printDatabaseEntries();
    }
}

void Database::sortByLastname(void)
{
    if(students_.empty())
    {
        cout << "Database is empty. Unable to sort students \n";
    }
    else
    {
        cout << "Sorting by lastname..\n";
        sort(students_.begin(), students_.end(), [](Student a, Student b)
        {
            return a.getLastName() < b.getLastName();
        });
        cout << "Database is sorted: \n";
        printDatabaseEntries();
    }
}

void Database::removeByIndexNo(int idxNo)
{
    students_.erase(students_.begin() + idxNo);
}