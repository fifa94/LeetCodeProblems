#include <string>
#include <iostream>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        int found = haystack.find(needle);
        if (found != std::string::npos)
        {
            //std::cout << "First occurrence is " << found << std::endl;
            return found;
        }
        return -1;
    }
};
int main()
{
    Solution SolutionObj;

    std::cout<<SolutionObj.strStr("leetcode", "leeto");
    return 0;
}