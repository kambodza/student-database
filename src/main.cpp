#include <iostream>
#include "database.hpp"
#include "student.hpp"
using namespace std;

int main()
{
    Database database;
    database.showCommands();
    // Student andrzej("andrzej", "duda", "krakow", 12, "46564564", Not_Specified);
    // database.add( andrzej );
    // andrzej.showStudent();
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main()
// {
//     vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

//     for (const string& word : msg)
//     {
//         cout << word << " ";
//     }
//     cout << endl;
// }