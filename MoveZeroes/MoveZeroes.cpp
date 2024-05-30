#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
 
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[j], nums[i]);
                j++;
            }
        }        
    }
};

int main()
{
    std::vector<int>nums {0,0,1};
    Solution SolutionObj;
    SolutionObj.moveZeroes(nums);
    return 0;
}