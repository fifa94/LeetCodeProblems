#include <iostream>
#include <functional>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

class Calculator
{
private:
    /* data */
public:
    Calculator(/* args */);
    ~Calculator();
    int add(int a, int b)
    {
        return a + b;
    }

    int subtract(int a, int b)
    {
        return a - b;
    }

    int multiply(int a, int b)
    {
        return a * b;
    }
};

Calculator::Calculator(/* args */)
{
}

Calculator::~Calculator()
{
}

int main()
{
    // cpp like
    std::function<int(int, int)> FunctionPointer[3] = {add, subtract, multiply};
    // c like
    int (*function_pointer[3])(int, int) = {add, subtract, multiply};

    Calculator CalculatorObj;
    // pristup k metode pomoci statickeho pristupu Calculator::*
    int (Calculator::*MethodPointer[3]) (int, int) = {&Calculator::add, &Calculator::multiply, &Calculator::subtract};

    return 0;
}