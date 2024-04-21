#include <vector>
#include <bits/stdc++.h>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        std::reverse(s.begin(), s.end());
        return;
    }
};

int main()
{
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution SolutionObj;
    SolutionObj.reverseString(s);
    return 0;
}