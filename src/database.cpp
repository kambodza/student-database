#include "database.hpp"

void Database::add( Student student )
{
    this->students_.push_back(student);
}

// vector<Student> Database::getEntries()
// {
//     return students_;
// }