#include <iostream>
class Solution {
public:
    int fib(int n) {
        
        if( n == 0)
        {
            return 0;
        }
        
        return ((n == 1) || (n == 2)) ? 1 :  fib(n -2) + fib(n - 1);
    }
};

int main()
{
    Solution SolutionObj;
    std::cout << SolutionObj.fib(0);
    return 0;
}