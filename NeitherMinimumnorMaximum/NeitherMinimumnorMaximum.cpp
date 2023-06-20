#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int findNonMinOrMax(std::vector<int>& nums) {
        
        if (nums.size() > 2)
        {
            std::sort(nums.begin(), nums.end());
        }
        else
        {
            return -1;
        }
        
        return nums[1];
    }
};

/*
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int findNonMinOrMax(std::vector<int>& nums) {
        
        if (nums.size() <= 2)
            return -1;

        std::sort(nums.begin(), nums.end());
    
        return nums[1];
    }
};
*/
int main()
{
    std::vector<int> nums {3,2,1,4};
    Solution SolutionObj;
    std::cout << SolutionObj.findNonMinOrMax(nums);
    return 0;
}