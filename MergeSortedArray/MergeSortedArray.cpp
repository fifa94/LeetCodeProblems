#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

class Solution
{
public:
    void merge(std::vector<int> nums1, int m, std::vector<int> nums2, int n)
    {
        std::vector<int> result (nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin(), [&](int& a, int& b){
            return a < b;
        });

        nums1.clear();

        for (int i = 0; i < result.size(); i++)
        {
            nums1.push_back(result[i]);
        }
    }
};

int main()
{
    std::vector<int> nums1 {1,2,3};
    std::vector<int> nums2 {2,5,6};
    int m = 3;
    int n = 3;

    Solution SolutionObj;
    SolutionObj.merge(nums1, m, nums2, n);
    int i = 0;
    return 0;
}