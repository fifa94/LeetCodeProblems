#include "Sorting.hpp"
#include <iostream>

int main()
{
    std::vector<int> buffer = {5, 3, 2, 4, 6, 1};

    BubleSort *BubleSortObj = new BubleSort(buffer);

    auto result = BubleSortObj->Sort();

    if (result.has_value())
    {
        buffer.swap(result.value());

        std::cout << "================" << std::endl;
        std::cout << "Sorted buffer" << std::endl;

        for (int i = 0; i < buffer.size(); i++)
        {
            if (i != 0)
            {
                std::cout << ", " << buffer[i];
            }
            else
            {
                std::cout << buffer[i];
            }
        }
    }
    else
    {
        std::cout << "Something went wrong during sorting";
    }

    delete BubleSortObj;

    return 0;
}