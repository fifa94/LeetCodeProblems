#include <string>
#include <iostream>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
 
        return haystack.find(needle);
    }
};
int main()
{
    Solution SolutionObj;

    std::cout<<SolutionObj.strStr("leetcode", "leeto");
    return 0;
}