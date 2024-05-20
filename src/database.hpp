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
    void add( Student student );
    // vector<Student> Database::getEntries();
    Database(/* args */);
    ~Database();
};

    
// Database::Database(/* args */)
// {
// }

// Database::~Database()
// {
// }
