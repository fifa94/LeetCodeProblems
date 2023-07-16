// uniformni inicializace
// int x{10};
#include <iostream>
[[deprecated("Nepouzivejte to")]] void fn()
{
};

int main()
{
    int value = 100;
    int x{110};
    // fn();
    switch (value)
    {
    case 100:
        std::cout << 100 << std::endl;
        [[falltrough]]
    [[likely]]case 200:
        std::cout << 200 << std::endl;
        break;
    default:
        break;
    }
    return 0;
}