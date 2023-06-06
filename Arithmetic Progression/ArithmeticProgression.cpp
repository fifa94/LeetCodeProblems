#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <set>

class Solution
{
public:
    bool canMakeArithmeticProgression(std::vector<int> &arr)
    {
        std::sort(std::begin(arr), std::end(arr));

        //std::set<int> set(arr.begin(), arr.end());

       // int sum = std::accumulate(set.begin(), set.end(), 0);
        //int sum1 = (static_cast<int>((arr.size() * (arr[0] + arr[arr.size() - 1]))) / 2);

        //std::cout <<  / 2) << std::endl;
        //std::cout << (static_cast<int>((arr.size() * (arr[0] + arr[arr.size() - 1]))) / 2) << std::endl;
        //bool var = ((static_cast<int>((arr.size() * (arr[0] + arr[arr.size() - 1]))) / 2) == std::accumulate(set.begin(), set.end(), 0));

       // if ((static_cast<int>((arr.size() * (arr[0] + arr[arr.size() - 1]))) / 2) == std::accumulate(set.begin(), set.end(), 0))
        //{
            
            for (int i = 0; i < arr.size(); i ++)
            {
                std::cout << "index: " << i << std::endl;
                if (i <= (arr.size() - 2))
                {
                    std::cout << "sum: " << abs(arr[i] - arr[i + 1]) << std::endl;
                    std::cout << "sum1: " << abs(arr[(arr.size() - 1) - i] - arr[(arr.size() - 1) - i - 1]) << std::endl;

                    
                    if (abs(arr[i] - arr[i + 1]) != abs(arr[0] - arr[1]) || (abs(arr[(arr.size() - 1) - i] - arr[(arr.size() - 1) - i - 1]) != abs(arr[0] - arr[1])) )
                    {
                        return 0;
                    }
                    
                }
            }
            return 1;
        //}
       // return 0;
    }
};

int main()
{
    std::vector<int> arr = {1,1,1,1};

    // std::vector<int> arr = {1,100};
    Solution SolutionObj;

    std::cout << "result: " << SolutionObj.canMakeArithmeticProgression(arr) << std::endl;

    return 0;
}