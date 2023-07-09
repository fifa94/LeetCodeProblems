#include <vector>
#include <iostream>
#include <string>

template<typename T>
void fn (T value)
{
    std::cout << "hodnota: " << value << std::endl;
}

// Metaprogramovani rekurzivni pouziti sablon
template<int N> class Factorial 
{
    public:
    static const int value = N * Factorial< N-1 >::value;
};

template<> class Factorial < 0 >
{
    public:
    static const int value = 1;
};

int main ()
{
    fn(1);
    fn(1.68);
    fn("Ahoj");
    std::vector<int> cisla = {1,2,3,4};

    std::cout << "hodnota faktorialu 5: " << Factorial<5>::value << std::endl;

    return 0;
}
// Lze vytvaret parcialne nebo plne specializovane sablony.
//parcialne
// tepllate<typename T> class Container <T, std::string>
//{
//
//}
//plne
// tepllate<> class Container <std::string, std::string>
//{
//
//}