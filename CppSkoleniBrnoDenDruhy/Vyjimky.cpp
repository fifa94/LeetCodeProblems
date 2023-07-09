#include<iostream>

class Human
{
private:
    int age;
public:
    Human(int);
    ~Human();
};

Human::Human(int age)
{
    if (age < 0)
    {
        throw "age is invalid";
    }
    this->age = age;
}

Human::~Human()
{
}

int main()
{
    try{
        Human franta(-200);
    }
    catch(const char* error){
        std::cout << error << std::endl;
    }
    
    /*
    try{
        ptr = new MyObj();
    }
    catch(const std::bad_alloc& ex){
        std::cerr << "Failed to get memory" << std::endl;
    }
    */

    return 0;
}