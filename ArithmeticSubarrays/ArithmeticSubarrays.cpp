#include <vector>
#include <iostream>
#include <algorithm>
class Solution
{
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int> &nums, std::vector<int> &l, std::vector<int> &r)
    {
        std::vector<bool> result;
        int koef = 0;
        
        for (int i = 0; i < l.size(); i++)
        {
            bool flag = false;
            std::vector<int> sub_vector(nums.begin() + l[i], nums.begin() + r[i] + 1);
            std::sort(sub_vector.begin(), sub_vector.end());

            koef = sub_vector[1] - sub_vector[0];

            for (int j = 1; j < sub_vector.size(); j++)
            {
                if (sub_vector[j] - sub_vector[j - 1] != koef)
                {
                    result.push_back(false);
                    flag = true;
                    break;
                }
                else
                {

                }
            }
            if (!flag)
            {
                result.push_back(true);
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> nums = {4, 6, 5, 9, 3, 7};
    std::vector<int> l = {0, 0, 2};
    std::vector<int> r = {2, 3, 5};

    Solution SolutionObj;
    std::vector<bool> result = SolutionObj.checkArithmeticSubarrays(nums, l, r);
    return 0;
}