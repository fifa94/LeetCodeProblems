#include <functional>
#include <array>
#include <iostream>

// Funkce vyssiho radu. High order function
void apply (int x, int y, const auto& fn)
{
    for(int i = 0; i < fn.size(); i++)
    {
        std::cout << "pole : "<< fn[i](x, y) << std::endl;
    }   
}


template <typename T>
void apply1(int x, int y,const T t)
{
    for (int i = 0; i < t.size(); i++)
    {
        std::cout << "template : "<< t[i](x, y) << std::endl;
    }
}

int main()
{
    std::array<std::function<int(int, int)>, 4> array{
        [](int x, int y) { return x + y; },
        [](int x, int y) { return x - y; },
        [](int x, int y) { return x * y; },
        [](int x, int y) { return x / y; },
    };

    apply1(1,2, array);
    apply(1,2, array);

    return 0;
}