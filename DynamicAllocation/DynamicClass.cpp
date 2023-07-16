#include <iostream>
#define SIZE 5

class DynamicClass
{
private:
    /* data */
public:
    DynamicClass(/* args */);
    ~DynamicClass();
    void msg (void){
        std::cout << "text" << std::endl;
    };
    void msg(int index){
        std::cout << "text: " << std::to_string(index) << std::endl;
    }
};

DynamicClass::DynamicClass(/* args */)
{
    std::cout << "created" << std::endl;
}

DynamicClass::~DynamicClass()
{
    std::cout << "deleted" << std::endl;
}


int main ()
{
    DynamicClass * DynamicObject = new DynamicClass;

    DynamicObject->msg();

    delete DynamicObject;

    DynamicClass * DynamicArray = new DynamicClass[5];

    for (int i = 0; i < SIZE; i++)
    {
        DynamicArray[i].msg(i);
    }
    
    delete [] DynamicArray;

    return 0;
}