#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            std::cout<<nums[i];
            if (nums[i] == nums[i + 1])
            {
                
                return true;
            }
            
        }

        return false;
    }
};

int main()
{

    std::vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    Solution SolutionObj;

    std::cout << SolutionObj.containsDuplicate(nums);

    return 0;
}