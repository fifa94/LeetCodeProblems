#include <iostream>
#include <unordered_map>

class Solution {
public:
    int climbStairs(int n) {

        std::unordered_map<int, int> results;

        return aux_climbingStairs(n, results);
    }

    int aux_climbingStairs(int n, std::unordered_map<int, int>& map)
    {
        if ((n == 1) || (n == 2))
        {
            return n;
        }

        if (map.find(n) == map.end())
        {
            map[n] = aux_climbingStairs(n - 1, map) + aux_climbingStairs(n - 2, map);
        }
        
        return map[n];
    }
};

int main()
{
    int n = 3;

    Solution SolutionObj;
    std::cout << SolutionObj.climbStairs(n);
    return 0;
}