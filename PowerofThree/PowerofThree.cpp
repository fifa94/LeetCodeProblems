#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {

        return ((n > 0) && (static_cast<double>(pow(3, static_cast<double>(std::ceil(static_cast<double>(std::log(n)) / 
        static_cast<double>(std::log(3)) * 100000000.0) / 100000000.0))) == n))? 1 : 0;

    }
};

int main()
{
    //int num = 43046720;
    //int num = 43046722;
    int num = 4782968;
    Solution SolutionObj;
    std::cout << SolutionObj.isPowerOfThree(num);
    return 0;
}