#include <iostream>
#include<vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
        /* smaller than pivot*/
        std::vector<int> smaller;
        /* greater than pivot */
        std::vector<int> greater;
        int number_of_pivot_occurrence = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                smaller.push_back(nums[i]);
            }
            else if(nums[i] > pivot)
            {
                greater.push_back(nums[i]);
            }
            else{
                number_of_pivot_occurrence++;
            }
        }
        nums.clear();
        nums.insert(nums.begin(), smaller.begin(), smaller.end());
        for (int i = 0; i < number_of_pivot_occurrence; i++)
        {
            nums.push_back(pivot);
        }
        nums.insert(nums.end(), greater.begin(), greater.end());
        return nums;
    }
};

int main ()
{
    std::vector<int> nums {9,12,5,10,14,3,10};
    int pivot = 10;
    Solution SolutionObj;
    SolutionObj.pivotArray(nums, pivot);
    return 0;
}