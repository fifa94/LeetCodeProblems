#include <iostream>
int sum(int num_of_elements)
{
    int result = 0;

    if (num_of_elements == 1)
    {
        return 1;
    }
    else
    {
        result = num_of_elements + sum(num_of_elements - 1);
    }
    return result;
}
int main()
{
    std::cout<<sum(6);
    return 0;
}