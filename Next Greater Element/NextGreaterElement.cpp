#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {

        std::vector<int> result;
        int nums2_max = -500;
        int position;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int x = 0; x < nums2.size(); x++)
            {
                if (nums1[i] == nums2[x])
                {
                    position = x;
                }

                if (nums2[x] > nums2_max)
                {
                    nums2_max = nums2[x];
                }
            }

            if (nums1[i] == nums2_max)
            {
                std::cout << nums1[i] << std::endl;
                result.push_back(-1);
            }
            else
            {
                for (int j = position + 1; j < nums2.size(); j++)
                {
                    if ((nums1[i] < nums2[j]) && (j != (nums2.size() - 1)))
                    {
                        result.push_back(nums2[j]);
                        break;
                    }
                }
                if ((position + 1) >= nums2.size())
                {
                    result.push_back(-1);
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums1 = {4,1,2};
    std::vector<int> nums2 = {1,3,4,2};
    Solution SolutionObj;
    SolutionObj.nextGreaterElement(nums1, nums2);

    return 0;
}

/*

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

ex3
[5,2,6,9,11,3,7]
*/