#include <string>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int numJewelsInStones(std::string jewels, std::string stones)
    {
        int count = 0;

        std::for_each(jewels.begin(), jewels.end(), [&] (char& jewels_char)
        {
            std::for_each(stones.begin(), stones.end(), [&] (char& stones_char)
            {
                if (jewels_char == stones_char)
                    count += 1;
            });
        });

        return count;
    }
};

int main()
{

    std::string jewels = "aA";
    std::string stones = "aAAbbbb";

    Solution SolutionObj;
    std::cout << SolutionObj.numJewelsInStones(jewels, stones);
}