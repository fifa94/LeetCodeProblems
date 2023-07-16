#include <string>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int numJewelsInStones(std::string jewels, std::string stones)
    {
   int count = 0;

    for (char jewels_char : jewels) {
        count += std::count_if(stones.begin(), stones.end(), [&](char& stones_char) {
            return jewels_char == stones_char;
        });
    }

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