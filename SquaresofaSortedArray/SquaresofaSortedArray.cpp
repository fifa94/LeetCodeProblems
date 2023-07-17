#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pow(nums[i], 2);
        }
        
        std::sort(nums.begin(), nums.end());
        
        return nums;
    }
};

int main()
{
    std::vector<int> nums = {-4,-1,0,3,10};

    Solution SolutionObj;
    SolutionObj.sortedSquares(nums);
    return 0;
}