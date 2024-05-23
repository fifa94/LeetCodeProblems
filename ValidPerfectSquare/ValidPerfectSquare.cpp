#include <iostream>
#include <math.h>

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int number = static_cast<int>(sqrt(num));
        return ((sqrt(num) - number) == 0)? 1:0;
    }
};

int main()
{
    int num = 16658;
    Solution SolutionObj;
    std::cout << SolutionObj.isPerfectSquare(num);

    return 0;
}