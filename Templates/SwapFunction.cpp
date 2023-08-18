#include <iostream>

template <typename T>
void SwapFunction(T *t, T *z)
{
    T AuxVariable = *z;
    *z = *t;
    *t = AuxVariable;
}

template <typename T>
class SwapClass
{
private:
    T _var1;
    T _var2;

public:
    SwapClass(){};
    void SwapVariables(T var1, T var2);
    void printVariables(void)
    {
        std::cout << "var1 = " << _var1 << std::endl;
        std::cout << "var2 = " << _var2 <<std::endl ;
    };
    ~SwapClass(){};
};

template <typename T>
void SwapClass<T>::SwapVariables(T var1, T var2)
{
    this->_var1 = var2;
    this->_var2 = var1;
    printVariables();
}

int main()
{
    int t = 3;
    int z = 5;

    SwapFunction(&t, &z);

    std::cout << "t = " << t << std::endl;
    std::cout << "z = " << z << std::endl;

    t = 3;
    z = 5;

    SwapClass<int> SwapObj;
    SwapObj.SwapVariables(t, z);

    return 0;
}