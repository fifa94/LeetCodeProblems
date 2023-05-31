#include <iostream>

template<int N> class Fib 
{
    public:
    static const int value = Fib< N-1 >::value + Fib < N-2 >::value;
};

template<> class Fib < 1 >
{
    public:
    static const int value = 1;
};

template<> class Fib < 2 >
{
    public:
    static const int value = 1;
};

template<> class Fib < 0 >
{
    public:
    static const int value = 0;
};

int main()
{
    std::cout << Fib<6>::value;
    return 0;
}