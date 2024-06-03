#include "database.hpp"
#include <algorithm>

void Database::addItem()
{
    auto studentToAdd = Student();
    studentToAdd.takeNameFromCin();
    studentToAdd.takeLastNameFromCin();
    studentToAdd.takeAddressFromCin();
    studentToAdd.takeIndexNumberFromCin();
    studentToAdd.takePeselFromCin();
    studentToAdd.takeGenderFromCin();
    students_.push_back(studentToAdd);
    std::cout << "Student is added!\n";
}

std::vector<Student> Database::getEntries()
{
    return students_;
}

void Database::commandsHandler()
{
    unsigned commandNo = 0;
    bool loopGoOn = true;

    while (loopGoOn)
    {
        printMenuItems();
        std::cin >> std::ws >> commandNo;
        switch (commandNo)
        {
        case 1:
            /* add student */
            addItem();
            break;

        case 2:
            /* remove student */
            removeByPositionNo(searchByIndexNo());
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
            sortByLastname();
            break;

        case 7:
            sortByPesel();
            break;

        case 10:
            loopGoOn = false;
            std::cout << "Closing program. See you soon! \n";
            break;
        
        default:
            std::cout << "This menu item is not supported, write ok + enter to continue \n";
            std::string noUseString;
            std::cin >> std::ws >> noUseString;
            break;
        }
    }
}

void Database::printMenuItems()
{
    std::cout << "\n" << "\n" << "\n" << "\n";
    std::cout << "////STUDENT-DATABASE menu choose option:\\\\\\\\" << "\n";
    std::cout << "1 - Add Student" << "\n";
    std::cout << "2 - Remove Student" << "\n";
    std::cout << "3 - Show all Students" << "\n";
    std::cout << "4 - Search Student by lastname" << "\n";
    std::cout << "5 - Search Student by PESEL" << "\n";
    std::cout << "6 - Sort Students by lastname" << "\n";
    std::cout << "7 - Sort Students by PESEL" << "\n";
    std::cout << "10 - Close program" << "\n";
}

void Database::printDatabaseEntries()
{
    unsigned studNo = 1;
    std::cout << "\n";
    if(students_.empty())
    {
        std::cout << "Database is empty. Unable to show students \n";
    }
    else
    {
        for(const Student& n : students_)
        {
            std::cout << studNo << ". ";
            n.showStudent();
            std::cout << "\n";
            studNo++;
        }
    }
}

void Database::searchByLastName()
{
    std::string nameToSearch;
    bool foundFlag = false;

    if(students_.empty())
    {
        std::cout << "Database is empty. Unable to search students \n";
    }
    else
    {
        std::cout << "Enter last name to search:\n";
        std::cin >> std::ws >> nameToSearch;

        for(const Student& n : students_)
        {
            if(n.getLastName() == nameToSearch)
            {
                std::cout << "Entry is found!\n";
                n.showStudent();
                std::cout << "\n";
                foundFlag = true;
            }
        }

        if( foundFlag == false )
        {
            std::cout << "Student named" << nameToSearch << "is not found!\n";
        }
    }
}

void Database::searchByPesel()
{
    std::string peselToSearch;
    bool foundFlag = false;

    if(students_.empty())
    {
        std::cout << "Database is empty. Unable to search students \n";
    }
    else
    {
        std::cout << "Enter PESEL to search:\n";
        std::cin >> std::ws >> peselToSearch;

        for(const Student& n : students_)
        {
            if(n.getPesel() == peselToSearch)
            {
                std::cout << "Entry is found!\n";
                n.showStudent();
                std::cout << "\n";
                foundFlag = true;
            }
        }

        if( foundFlag == false )
        {
            std::cout << "Student with PESEL " << peselToSearch << " is not found!\n";
        }
    }

}
int Database::searchByIndexNo()
{
    int idxToSearch;
    bool foundFlag = false;

    int position = -1;

    if(!students_.empty())
    {
        std::cout << "Enter Index number to search:\n";
        std::cin >> std::ws >> idxToSearch;

        auto it = std::find_if(std::begin(students_), std::end(students_), 
                            [idxToSearch](const Student& student) { return student.getIndexNo() == idxToSearch; });

        if (it == std::end(students_)) 
            std::cout << "Student with indexNumber " << idxToSearch << " is not found!\n";
        else 
        {
            it->showStudent(); 
            position = std::distance( students_.begin(), it );
        }
        
    }
    else
        std::cout << "Database is empty. Unable to search students \n";

    return position;
}

void Database::sortByPesel()
{
    if(students_.empty())
    {
        std::cout << "Database is empty. Unable to sort students \n";
    }
    else
    {
        std::cout << "Sorting by PESEL..\n";
        sort(students_.begin(), students_.end(), [](const Student& a, const Student& b)
        {
            return a.getPesel() < b.getPesel();
        });
        std::cout << "Database is sorted: \n";
        printDatabaseEntries();
    }
}

void Database::sortByLastname()
{
    if(students_.empty())
    {
        std::cout << "Database is empty. Unable to sort students \n";
    }
    else
    {
        std::cout << "Sorting by lastname..\n";
        sort(students_.begin(), students_.end(), [](const Student& a, const Student& b)
        {
            return a.getLastName() < b.getLastName();
        });
        std::cout << "Database is sorted: \n";
        printDatabaseEntries();
    }
}

void Database::removeByPositionNo(int posNo)
{
    if(posNo != -1)
    {
        std::cout << "Distance" << std::distance(students_.begin(), students_.end()) << "\n";
        if( posNo > std::distance(students_.begin(), students_.end()) )
            std::cout << "Position is bigger than size of students vector!\n";
        else
        {
            students_.erase(students_.begin() + posNo);
            std::cout << "Student is erased successfully!\n";
        }
    }
    else
        std::cout << "Unable to delete student!\n";
}