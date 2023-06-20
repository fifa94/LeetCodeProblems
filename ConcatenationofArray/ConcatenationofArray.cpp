#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> result = nums;

        for(int i = 0; i < nums.size(); i++){
            result.push_back(nums[i]);
        }
        
        return result;
    }
};

int main()
{
    std::vector<int> nums {1,2,1};
    Solution SolutionObj;
    SolutionObj.getConcatenation(nums);
    return 0;
}