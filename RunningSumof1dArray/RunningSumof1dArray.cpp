#include <vector>
#include <iostream>

class Solution
{
public:
    std::vector<int> runningSum(std::vector<int> &nums)
    {

        std::vector<int> result;
        result.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            result.push_back(nums[i] + result[result.size() - 1]);
        }

        return result;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3, 4};

    Solution SolutionObj;
    SolutionObj.runningSum(nums);

    return 0;
}