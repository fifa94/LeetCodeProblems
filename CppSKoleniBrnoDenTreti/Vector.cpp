#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec{8, 4, 15};
    // pokud nedodam <int> a zaroven dodam data, tak si kompilator domysli typ pomoci CTAD
    // std::vector vec {8,4,15};

    std::vector<int>::iterator ukazovatko = vec.begin();

    std::cout << *ukazovatko << std::endl;

    ukazovatko++;

    std::cout << *ukazovatko << std::endl;

    for (auto ukazovatko = vec.begin(); ukazovatko != vec.end(); ukazovatko++)
        std::cout << *ukazovatko << std::endl;


    
}
