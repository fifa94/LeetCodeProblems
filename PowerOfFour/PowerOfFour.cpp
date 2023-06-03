#include <iostream>
#include <math.h>
#include<limits>

class Solution
{
public:
    bool isPowerOfFour(int n)
    {

        if (std::fmod(((log(n)) / (log(4))), 1.0) == 0)
        {
            return 1;
        }

        return 0;
    }

        bool isPowerOfTwo(int n)
    {   /*
        auto result1 = floor(((log(n) / log(2)) * pow(10, 10))) / pow(10, 10);
        auto result = static_cast<int>((log(n) / log(2))) * 10000 / 10000.0;

        auto resul2 = (log(n)) / (log(2));
        
        float check = std::fmod(result, 1.0);

        if (std::fmod(((log(n)) / (log(2))), 1.0) == 0)
        {
            return 1;
        }
        */
       /*Kvuli tomu, ze pocitam s float cisly, doplatil jsem na floating point number precision. 
       Cislo by melo byt presne do nejakych 15 cisel za desetinou carkou. 
       Proto jsem musel najit reseni, ktere osekne cisle v tomto pripade za 10 desetinymi cisly.
       */
        return (std::fmod(floor(((log(n) / log(2)) * pow(10, 10))) / pow(10, 10), 1.0) == 0) ? 1 : 0; ;
    }
};



int main()
{
    Solution SolutionObj;
    //std::cout<<SolutionObj.isPowerOfFour(1);
    //std::cout<<SolutionObj.isPowerOfTwo(536870912);
    //std::cout<<SolutionObj.isPowerOfTwo(2097151);
    std::cout<<SolutionObj.isPowerOfTwo(262145);
    return 0;
}