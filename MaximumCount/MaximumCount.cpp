#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        int positive = 0;
        int negative = 0;
        std::for_each(nums.begin(), nums.end(),[&] (int& i){
            if (i > 0)
                positive += 1;
            
            if (i < 0)
                negative += 1;    
        });

        return (negative > positive)? negative : positive;
    }
};

int main()
{
    std::vector<int> grid {5,20,66,1314};
    Solution SolutionObj;
    std::cout << SolutionObj.maximumCount(grid);
}