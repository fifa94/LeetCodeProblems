#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Calculator
{
private:
    T _var1;
    T _var2;

public:
    Calculator(T var1, T var2);
    ~Calculator();
    T Plus(void);
    T Minus(void);
    T Multiplication(void);
    T Division(void);
    void ChangeVariables(T var1, T var2);
    std::string Print(T result);
    void DisplayResults(void);
};

template <typename T>
Calculator<T>::Calculator(T var1, T var2)
{
    this->_var1 = var1;
    this->_var2 = var2;
}

template <typename T>
Calculator<T>::~Calculator()
{
}

template <typename T>
T Calculator<T>::Plus(void)
{
    return this->_var1 + this->_var2;
}

template <typename T>
T Calculator<T>::Minus(void)
{
    return this->_var1 - this->_var2;
}

template <typename T>
T Calculator<T>::Multiplication(void)
{
    return this->_var1 * this->_var2;
}

template <typename T>
T Calculator<T>::Division(void)
{
    if (this->_var2 == 0)
    {
        throw std::runtime_error("Division by zero");
    }

    return this->_var1 / this->_var2;
}

template <typename T>
void Calculator<T>::ChangeVariables(T var1, T var2)
{
    this->_var1 = var1;
    this->_var2 = var2;
}

template <typename T>
std::string Calculator<T>::Print(T result)
{
    std::string result_str;
    result_str = "result " + std::to_string(result);
    return result_str;
}

template <typename T>
void Calculator<T>::DisplayResults(void)
{
    std::cout << "Plus -> " << Print(Plus()) << std::endl;
    std::cout << "Minus -> " << Print(Minus()) << std::endl;
    std::cout << "Multiplication -> " << Print(Multiplication()) << std::endl;
    std::cout << "Division -> " << Print(Division()) << std::endl;
}

int main()
{
    try
    {
        Calculator<double> CalculatorObj(5.0, 0.0);
        CalculatorObj.DisplayResults();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}