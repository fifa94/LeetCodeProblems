#include <iostream>
#include <string>

using std::endl;

namespace Skoleni
{
    std::string msg_hello = "Hello";
}
// Vnorovani namespacu
namespace A
{
    int x = 10;
    namespace B
    {
        int x = 100;
        namespace C
        {
            int x = 1000;
        }
    }
}

int main()
{
    std::cout << Skoleni::msg_hello << endl;

    std::cout << A::x << std::endl;
    std::cout << A::B::x << std::endl;
    std::cout << A::B::C::x << std::endl;
    
    return 0;
}