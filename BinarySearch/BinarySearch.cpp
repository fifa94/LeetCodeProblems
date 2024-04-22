#include <vector>
#include <iostream>
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {

        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(std::vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
        {
            //std::cout << "Not found" << std::endl;
            return -1;
        }
        else if (nums[(left + right) / 2] == target)
        {
            //std::cout << "Found at index: " << (left + right) / 2 << std::endl;
            return (left + right) / 2;
        }
        else if (nums[(left + right) / 2] < target)
        {
            return binarySearch(nums, target, ((left + right) / 2) + 1, right);
        }
        else
        {
            return binarySearch(nums, target, left, ((left + right) / 2) - 1);
        }
    }
};

int main()
{

    std::vector<int> nums{-1, 0, 3, 5, 9, 12, 13, 14};
    Solution SolutionObj;
    std::cout << SolutionObj.search(nums, 9);

    return 0;
}