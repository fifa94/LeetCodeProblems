
#include <iostream>
#include <vector>

int odd_even_numbeers (int number)
{
    if (number % 2 == 0)
    {
        std::cout << "Odd  number: "<< number << std::endl;
    }
    else
    {
        std::cout << "Even number: "<< number << std::endl;
    }

    if (number > 0)
    {
        return odd_even_numbeers(number - 1);
    }
    return 0;
}

int main()
{ 
    odd_even_numbeers(10);
    return 0;
}