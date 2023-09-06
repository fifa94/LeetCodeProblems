#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

class Solution
{
public:
    std::string licenseKeyFormatting(std::string s, int k)
    {
        std::string result;
        int spacer = 0;
        for (auto i = s.end() - 1; i != s.begin(); i--)
        {
            if (*i != 45)
            {
                if (spacer == (k))
                {
                    spacer = 0;
                    result.append("-");
                }
                spacer++;
                result.push_back(toupper(*i));
            }
        }
        if (*s.begin() != 45)
        {
            if (spacer == (k))
            {
                result.append("-");
            }
            result.push_back((toupper(*s.begin())));
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{

    Solution SolutionObj;
    // SolutionObj.licenseKeyFormatting("5F3Z-2e-9-w", 4);
    SolutionObj.licenseKeyFormatting("--a-a-a-a--", 2);
    return 0;
}