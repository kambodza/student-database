#pragma once
#include "student.hpp"
#include "gender.hpp"
#include <vector>


class Database
{
private:
    std::vector<Student> students_;
public:
    void addItem();
    std::vector<Student> getEntries();
    void commandsHandler();
    void printMenuItems();
    void printDatabaseEntries();
    void searchByLastName();
    void searchByPesel();
    int searchByIndexNo();
    void sortByPesel();
    void sortByLastname();
    void removeByIndexNo(int idxNo);
};
