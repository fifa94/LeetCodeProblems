#include <iostream>
#include <vector>
#include <array>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::vector<int> result;
         for (int index = 0; index < nums.size(); index++)
         {
            for (int sum_index = 0; sum_index < nums.size(); sum_index++)
            {
                if (((nums[index] + nums[sum_index]) == target) && ((index != sum_index)))
                {
                    result.push_back(index);
                }
            }
        }
        return result;
    }
};

int main()
{

    return 0;
}