#include<iostream>

int first_natural_elements(int num, int index=1)
{
    if (num <= 0)
    {
        return -1;
    }

    if (num == index)
    {
        std::cout<< ", " << index;
        return 1;
    }
    else
    {
        (index == 1)? std::cout << index : std::cout<< ", " << index;
        return first_natural_elements(num, index + 1);
    }

}

int main ()
{
    first_natural_elements(50);
    return 0;
}