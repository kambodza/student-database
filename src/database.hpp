#pragma once
#include "student.hpp"
#include "gender.hpp"
#include <vector>

using namespace std;


class Database
{
private:
    vector<Student> students_;
public:
    void addItem();
    vector<Student> getEntries(void);
    void commandsHandler(void);
    void printMenuItems(void);
    void printDatabaseEntries(void);
    void searchByLastName(void);
    void searchByPesel(void);
    int searchByIndexNo(void);
    void sortByPesel(void);
    void sortByLastname(void);
    void removeByIndexNo(int idxNo);
};
