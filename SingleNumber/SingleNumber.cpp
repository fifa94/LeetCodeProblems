#include <vector>
#include <iostream>
#include <algorithm>
#include <set>


class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int count = 0;
        int value = -2;

        std::set<int> vec(nums.begin(), nums.end());

        std::for_each(vec.begin(), vec.end(),[&] (const int& element) {

            count = 0;

            count += std::count(nums.begin(), nums.end(), element);

            if(count == 1)
            {
                value = element;
                return;
            }
        });

        return value;
        /*

        for (int i = 0; i < vec.size(); i++)
        {
            count = 0;

            for (int x = 0; x < nums.size(); x++)
            {
                //value = nums[i];
                //value1 = nums[x];

                if (vec[i] == nums[x])
                {
                    count += 1;
                }
            }

            if (count == 1)
            {
                return nums[i];
            }
            
        }
        */
    }
};

int main()
{
    std::vector<int> numbers{2, 2, 1};
    Solution SolutionObj;

    std::cout << SolutionObj.singleNumber(numbers);
}