#include<vector>
#include<iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        
        int close_value = 0;
        int index_storage = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
            else
            {
                /* code */
            }
            
            
        }
        
    }
};


int main()
{
    std::vector<int> data = {1,3,5,6};

    Solution SolutionObj;
    SolutionObj.searchInsert(data, 5);
    return 0;
}