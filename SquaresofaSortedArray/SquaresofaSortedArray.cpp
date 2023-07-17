#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {

        int i = 0;
        int j = nums.size() - 1;

        while (i <= j)
        {
            if (i < j)
            {
                nums[j] = pow(nums[j], 2);
                j--;
            }

            nums[i] = pow(nums[i], 2);
            i++;
        }

        std::sort(nums.begin(), nums.end());
        // 4,9,9,49,121]
        return nums;
    }
};

int main()
{
    std::vector<int> nums = {-7, -3, 2, 3, 11};

    Solution SolutionObj;
    SolutionObj.sortedSquares(nums);
    return 0;
}