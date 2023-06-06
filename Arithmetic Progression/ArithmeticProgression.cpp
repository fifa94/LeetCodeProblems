#include <vector>
#include <iostream>
#include <math.h>
#include <vector>
#include <math.h>
#include <algorithm>

class Solution
{
public:
    bool canMakeArithmeticProgression(std::vector<int> &arr)
    {
        std::sort(std::begin(arr), std::end(arr));

        for (int i = 2; i < arr.size(); i++)
        {
            if((arr[i] - arr [i - 1]) != arr[1] - arr[0])
                return 0;
        }
        return 1;
    }
};

int main()
{
    //std::vector<int> arr = {1, 1, 1, 1};
    std::vector<int> arr = {3,5,1};

    // std::vector<int> arr = {1,100};
    Solution SolutionObj;

    std::cout << "result: " << SolutionObj.canMakeArithmeticProgression(arr) << std::endl;

    return 0;
}