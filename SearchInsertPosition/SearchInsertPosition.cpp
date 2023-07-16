#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {

        auto result = std::find(nums.begin(), nums.end(), target);

        if (result == nums.end())
        {
            if (target < nums[nums.size() - 1])
            {
                    return (std::find_if(nums.begin(), nums.end(), [&](int number)
                                                { return (number > target); }) - nums.begin());
            }
            else
            {
                return nums.size();
            }
        }
        
        return (result - nums.begin());
    }
};

int main()
{
    std::vector<int> data = {1, 3, 5, 6};

    Solution SolutionObj;
    std::cout << SolutionObj.searchInsert(data, 5);
    return 0;
}