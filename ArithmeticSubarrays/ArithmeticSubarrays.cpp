#include<vector>
#include<iostream>

class Solution {
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        
    }
};

int main()
{
    std::vector<int> nums = {4,6,5,9,3,7};
    std::vector<int> l = {0,0,2};
    std::vector<int> r = {2,3,5};

    Solution SolutionObj;
    SolutionObj.checkArithmeticSubarrays(nums,l, r);
    return 0;
}