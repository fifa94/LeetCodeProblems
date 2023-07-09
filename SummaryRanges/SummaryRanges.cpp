#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        std::vector<std::string> results;

        if (nums.size() > 1)
        {
            long long int begin_of_range = nums[0];
            long long int end_of_range = 0;
            int end_of_range_old = 0;
            for (int i = 1; i < nums.size(); i++)
            {
                if ((static_cast<long long int>(nums[i]) - nums[i - 1]) == 1)
                {
                    end_of_range = nums[i];
                }
                else if ((((static_cast<long long int>(nums[i])) - nums[i - 1]) > 1) && (i < nums.size()))
                {
                    if (end_of_range_old == end_of_range)
                    {
                        begin_of_range = nums[i];
                        results.push_back(std::to_string(nums[i - 1]));
                    }
                    else
                    {
                        results.push_back(std::to_string(begin_of_range) + "->" + std::to_string(end_of_range));
                        begin_of_range = nums[i];
                    }
                    end_of_range_old = end_of_range;
                }
            }
            if ((static_cast<long long int>(nums[nums.size() - 1]) - nums[nums.size() - 2]) > 1)
            {
                results.push_back(std::to_string(nums[nums.size() - 1]));
            }
            else
            {
                results.push_back(std::to_string(begin_of_range) + "->" + std::to_string(end_of_range));
            }
        }
        else if (nums.size() == 1)
        {
            results.push_back(std::to_string(nums[nums.size() - 1]));
        }
        return results;
    }
};
int main()
{
    // std::vector nums{0, 1, 2, 4, 5, 7};
    std::vector nums{-2147483648,-2147483647,2147483647};
    // std::vector nums{0, 2, 3, 4, 6, 8, 9};
    Solution SolutionObj;

    SolutionObj.summaryRanges(nums);
    return 0;
}