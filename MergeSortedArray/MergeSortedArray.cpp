#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

class Solution
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        std::vector<int> result(nums1.size() + nums2.size());

        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.end(), result.begin(), [&](int &a, int &b)
        {
            return a < b;
        });

        std::memcpy(&nums1[0], &result[0], sizeof(int) * nums1.size());
    }
};

int main()
{
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};
    int m = 3;
    int n = 3;

    Solution SolutionObj;
    SolutionObj.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }

    return 0;
}