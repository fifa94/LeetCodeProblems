#include <string>
#include <string.h>
#include <iostream>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
   
        if (s.size() == t.size())
        {
            int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int cnt = 0;

            for (int x = 0; x < t.length(); x++)
            {
                if (strncmp(&s[i], &t[x], 1) == 0)
                {
                    cnt++;
                }
            }

            if (cnt == 0)
            {
                return 0;
            }
            
        }

        return 1;
        }
        
        return 0;
    }
};

int main()
{

    Solution SolutionObj;
    std::cout << SolutionObj.isAnagram("a", "ar");

    return 0;
}