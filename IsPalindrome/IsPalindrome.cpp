#include <math.h>
#include<iostream>
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x >= 10)
        {
            int i = 1;
            int x_copy = x;
            int last_digit = 0;
            int x_reverse = 0;

            do
            {
                last_digit = x % 10;

                x_reverse = (x_reverse * 10) + last_digit;

                x = x / 10;
                
                i ++;

            } while(x > 0);

            if (x_copy != x_reverse)
            {
                return 0;
            }

            return 1;
        }
        else if ((x < 10) && (x > 0))
        {
            return 1;
        }
        return 0; 
    }
};

int main()
{

    Solution SolutionObj;
    std::cout<<SolutionObj.isPalindrome(1);

    return 0;
}