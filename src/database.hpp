#pragma once
#include "student.hpp"

enum class Gender 
{
    Male,
    Female
};

class Database
{
private:
    /* data */
public:
    void add( const Student & s );
    Database(/* args */);
    ~Database();
};

    
Database::Database(/* args */)
{
}

Database::~Database()
{
}
