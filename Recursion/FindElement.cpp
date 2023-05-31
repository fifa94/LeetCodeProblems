#include <vector>
#include <iostream>

int FindElement(int searched_number, int index, std::vector<int> &nums)
{
    if (index >= nums.size())
    {
        return -1;
    }

    if (searched_number == nums[index])
    {
        return index;
    }

    return FindElement(searched_number, index + 1, nums);

};

int main()
{
    std::vector<int> nums_v = {5, 6, 8, 9, 4, 99, 7, 8, 9, 0};

    std::cout << FindElement(99, 0, nums_v);

    return 0;
}
