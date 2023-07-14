#include <iostream>
#include <string>
int main()
{
    int *dyn_int = new int;

    *dyn_int = 5;

    char *dyn_char = new char;

    *dyn_char = 'C';

    std::string *dyn_str = new std::string;

    *dyn_str = "ahoj";

    std::cout << "Allocated int: " << *dyn_int << std::endl;
    std::cout << "Allocated char: " << *dyn_char << std::endl;
    std::cout << "Allocated str: " << *dyn_str << std::endl;

    delete dyn_int;
    delete dyn_char;
    delete dyn_str;
    return 0;
}