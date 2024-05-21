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
    void showCommands(void);
    void printMenuItems(void);
};
