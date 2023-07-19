#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> runningSum(std::vector<int> &nums)
    {

        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = sum;
        }

        return nums;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3, 4};

    Solution SolutionObj;
    SolutionObj.runningSum(nums);

    return 0;
}