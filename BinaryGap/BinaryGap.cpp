#include <iostream>
#include <bitset>
#include <algorithm>

class Solution
{
public:
    int binaryGap(int n)
    {
        std::bitset<sizeof(int) * 8> binaryNumber(n);
        int last = -1;
        int gap = 0;

        for (int i = 0; i < binaryNumber.size(); i++)
        {
            if ((binaryNumber[i] == 1))
            {
                if (last >= 0)
                {
                    int diff = i - last;
                    gap = std::max(gap, diff);
                }
                last = i;
            }
        }
        return gap;
    }
};

int main()
{
    // int n = 6;
    int n = 6;
    Solution SolutionObje;
    std::cout << SolutionObje.binaryGap(n) << " Distance" << std::endl;
    return 0;
}