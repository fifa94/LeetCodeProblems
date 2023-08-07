#include <vector>
#include <iostream>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {

        std::map<int, int> result_map;
        int result = 0;
        int occurrence = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            result_map[nums[i]] += 1; 
        }

        for (auto it = result_map.begin(); it != result_map.end(); it++)
        {
            if (it->second > result)
            
                result = it->second;
                occurrence = it->first;  
        }
    
        return occurrence;
    }
};

int main ()
{
    std::vector<int> nums {3,3,4};
    Solution SOlutionObj;
    std::cout << SOlutionObj.majorityElement(nums);
    return 0;
}