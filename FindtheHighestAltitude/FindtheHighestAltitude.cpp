#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
    int largestAltitude(std::vector<int> &gain)
    {
        int altitude_old = 0;
        int altitude = 0;

        std::for_each(gain.begin(), gain.end(), [&] (int gain) {
            altitude += gain;
            altitude_old = std::max (altitude_old, altitude);
        });

        return altitude_old;
    }
};

int main()
{

    std::vector<int> gain{-5, 1, 5, 0, -7};

    Solution SolutionObj;
    std::cout << SolutionObj.largestAltitude(gain);
}