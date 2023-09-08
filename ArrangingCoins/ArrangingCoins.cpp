#include <iostream>

class Solution
{
public:
    int arrangeCoins(int n)
    {
        long int sum = 0;
        int i = 1;
        while (n > 0)
        {
            sum = sum + (i);
            n = n - i;
            if (n > 0)
            {
                i++;
            }
        }
        return (n == 0)? i : i-1; 
    }
};

int main()
{
    Solution SolutionObj;
    std::cout << SolutionObj.arrangeCoins(2147483647);
    return 0;
}