#include <vector>
#include <iostream>
#include <algorithm>
/*

0 <= i < j < nums.length

When i = 0 and j = 1: the first digit of nums[0] is 2, and the last digit of nums[1] is 5. We can confirm that 2 and 5 are coprime, since gcd(2,5) == 1.
When i = 0 and j = 2: the first digit of nums[0] is 2, and the last digit of nums[2] is 1. Indeed, gcd(2,1) == 1.
When i = 1 and j = 2: the first digit of nums[1] is 5, and the last digit of nums[2] is 1. Indeed, gcd(5,1) == 1.
When i = 1 and j = 3: the first digit of nums[1] is 5, and the last digit of nums[3] is 4. Indeed, gcd(5,4) == 1.
When i = 2 and j = 3: the first digit of nums[2] is 1, and the last digit of nums[3] is 4. Indeed, gcd(1,4) == 1.
*/

class Solution
{
public:
    int countBeautifulPairs(std::vector<int> &nums)
    {
        int cnt = 0;
        int number_1 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                number_1 = nums[i];
                if (number_1 > 9)
                {

                    while (number_1 > 9)
                    {
                        number_1 = number_1 / 10;
                    }
                    
                }
            
                //std::string number1_str = std::to_string(nums[i]);
                //int number1 = number1_str[0] - '0';

                if ((std::__gcd(number_1, (nums[j] % 10)) == 1))
                {
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};

int main()
{
    std::vector<int> nums{756, 1324, 2419, 495, 106, 111, 1649, 1474, 2001, 1633, 273, 1804, 2102, 1782, 705, 1529, 1761, 1613, 111, 186, 412};
    Solution SolutionObj;
    std::cout << SolutionObj.countBeautifulPairs(nums);
    return 0;
}