#include <iostream>
#include <math.h>

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
};

int main()
{
    Solution SolutionObj;
    std::cout<<SolutionObj.isPowerOfFour(1);
    return 0;
}